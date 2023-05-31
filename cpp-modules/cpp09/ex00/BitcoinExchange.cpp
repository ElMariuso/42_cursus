/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:54:11 by root              #+#    #+#             */
/*   Updated: 2023/05/27 16:10:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Constructor */
BTC::BTC(const std::string& path)
{
    int ret;

    /* Read file .csv */
    ret = this->readFile("data.csv");
    if (ret)
        throw (std::runtime_error("Could not database."));
    /* Parsing .csv */
    this->_database = this->processFile(",");
    /* Read file .txt */
    ret = this->readFile(path);
    if (ret)
        throw (std::runtime_error("Could not open file."));
    /* Parsing .txt */
    this->_storage = this->processFile("|");
}

/* Copy */
BTC::BTC(const BTC& rhs) { *this = rhs; }

BTC& BTC::operator=(const BTC& rhs)
{
    if (*this == rhs)
        return (*this);
    this->_buffer = rhs._buffer;
    this->_database = rhs._database;
    this->_storage = rhs._storage;
    return (*this);
}

/* Destructor */
BTC::~BTC() {}

/* Operators */
bool BTC::operator==(const BTC& rhs) const { return (this->_buffer == rhs._buffer && this->_database == rhs._database && this->_storage == rhs._storage); }

/* Utils */
int BTC::readFile(std::string path)
{
    std::fstream        file;
    std::string         tmp_buffer;
    std::string         line;

    file.open(path.c_str(), std::ifstream::in);
    if (!file.is_open())
        return (1);
    std::getline(file, line);
    while (std::getline(file, line))
        tmp_buffer += this->removeSpaces(line) + "\n";
    this->_buffer = tmp_buffer.c_str();
    file.close();
    return (0);
}

std::vector<std::pair<std::string, std::string> > BTC::processFile(std::string get)
{
    std::vector<std::pair<std::string, std::string> >   ret;
    std::istringstream                                  iss(this->_buffer);
    std::string                                         line;
    std::string                                         date;
    std::string                                         value;
    std::size_t                                         pos;
    int                                                 i;
    
    i = 0;
    while (std::getline(iss, line))
    {
        pos = line.find(get);
        if (pos != std::string::npos)
        {
            date = line.substr(0, pos);
            value = line.substr(pos + 1);
            
            std::istringstream  value_stream(value);
            float               float_value;
            if (!(value_stream >> float_value))
                ret.push_back(std::make_pair("Error: bad conversion.", ""));
            else if (float_value < 0)
                ret.push_back(std::make_pair("Error: not a positive number.", ""));
            else if (float_value > 1000)
                ret.push_back(std::make_pair("Error: too large a number.", ""));
            else if (this->isValidFormat(date) == false)
                ret.push_back(std::make_pair("Error: invalid date format.", ""));
            else
                ret.push_back(std::make_pair(date, value));
        }
        else
            ret.push_back(std::make_pair("Error: bad input => " + line, ""));
        i++;
    }
    return (ret);
}

void BTC::printAll()
{
    std::vector<std::pair<std::string, std::string> >::const_iterator   it;
    
    it = this->_storage.begin();
    while (it != this->_storage.end())
    {
        if (it->second == "")
            std::cout << it->first << std::endl;
        else
            std::cout << it->first << " => " << it->second << " = " << this->calculValue(it->first, it->second) << std::endl;
        it++;
    }
}

std::string BTC::removeSpaces(const std::string& str)
{
    std::string result;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            result += str[i];
    }
    return (result);
}

float BTC::calculValue(std::string date, std::string value)
{
    float                                                               db_value;
    float                                                               in_value;
    std::vector<std::pair<std::string, std::string> >::const_iterator   it;
    bool                                                                is_found;
    
    db_value = 0.0f;
    std::istringstream  value_stream(value);
    value_stream >> in_value;
    it = this->_database.begin();
    is_found = false;
    while (it != this->_database.end())
    {
        if (it->first == date)
        {
            std::istringstream  value_stream(it->second);
            value_stream >> db_value;
            is_found = true;
        }
        it++;
    }
    if (is_found == false)
        db_value = this->closestDateValue(date);
    return (in_value * db_value);
}

float BTC::closestDateValue(std::string date)
{
    float                                                               closest_value;
    float                                                               closest_diff;
    std::vector<std::pair<std::string, std::string> >::const_iterator   it;
    std::string                                                         db_date;
    std::string                                                         db_value;
    float                                                               diff;

    closest_value = 0.0f;
    closest_diff = std::numeric_limits<float>::max();
    it = this->_database.begin();
    while (it != this->_database.end())
    {
        db_date = it->first;
        db_value = it->second;
        diff = std::fabs(std::atof(db_date.c_str()) - std::atof(date.c_str()));
        if (diff < closest_diff)
        {
            closest_value = std::atof(db_value.c_str());
            closest_diff = diff;
        }
        ++it;
    }
    return (closest_value);
}

/* Booleans */
bool    BTC::isValidFormat(const std::string& date)
{
    int     year;
    int     month;
    int     day;

    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7) 
            continue ;
        if (!std::isdigit(date[i]))
            return (false);
    }
    std::istringstream(date.substr(0, 4)) >> year;
    std::istringstream(date.substr(5, 2)) >> month;
    std::istringstream(date.substr(8, 2)) >> day;
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) 
        return (false);
    if (month % 2 != 0)
    {
        if (day > 30)
            return (false);
    }
    if (month == 2)
    {
        if (this->isLeapYear(year) == false && day > 28)
            return (false);
        else if (day > 29)
            return (false);
    }
    return (true);
}

bool BTC::isLeapYear(int year)
{
    if (year % 4 != 0)
        return (false);
    if (year % 100 == 0 && year % 400 != 0)
        return (false);
    return (true);
}

/* Getter */
std::string BTC::getBuffer() { return (this->_buffer); }
std::vector<std::pair<std::string, std::string> > BTC::getDatabase() { return (this->_database); }
std::vector<std::pair<std::string, std::string> > BTC::getStorage() { return (this->_storage); }