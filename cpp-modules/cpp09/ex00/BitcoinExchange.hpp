/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:54:08 by root              #+#    #+#             */
/*   Updated: 2023/05/27 16:07:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

/* Includes ***************************************************************** */

# include <iostream>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include <cstring>
# include <string>
# include <vector>
# include <cctype>
# include <cstdlib>
# include <cmath>
# include <limits>
# include <utility>

/* Class ******************************************************************** */

class BTC
{
    /* Member functions ********************************************************* */
    public:
        /* Constructor */
        BTC(const std::string& path);

        /* Copy */
        BTC(const BTC& rhs);
        BTC& operator=(const BTC& rhs);

        /* Destructor */
        ~BTC();

        /* Operators */
        bool operator==(const BTC& rhs) const;

        /* Utils */
        int                                                 readFile(std::string path);
        std::vector<std::pair<std::string, std::string> >   processFile(std::string get);
        void                                                printAll();
        std::string                                         removeSpaces(const std::string& str);
        float                                               calculValue(std::string date, std::string value);
        float                                               closestDateValue(std::string date);

        /* Booleans */
        bool                                                isValidFormat(const std::string& date);
        bool                                                isLeapYear(int year);

        /* Getter */
        std::string                                         getBuffer();
        std::vector<std::pair<std::string, std::string> >   getDatabase();
        std::vector<std::pair<std::string, std::string> >   getStorage();

    /* Attributes *************************************************************** */
    private:
        std::string                                         _buffer;
        std::vector<std::pair<std::string, std::string> >   _database;
        std::vector<std::pair<std::string, std::string> >   _storage;
};

#endif