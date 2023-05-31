/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:41:24 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/04 10:42:26 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";closed" << std::endl;
    Account::_nbAccounts--;
    Account::_totalAmount -= this->_amount;
}

int Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << Account::_nbAccounts;
    std::cout << ";total:" << Account::_totalAmount;
    std::cout << ";deposits:" << Account::_totalNbDeposits;
    std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";deposit:" << deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal <= this->_amount)
    {
        _displayTimestamp();
        std::cout << " index:" << this->_accountIndex;
        std::cout << ";p_amount:" << this->_amount;
        std::cout << ";withdrawal:" << withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		std::cout << ";amount:" << this->_amount;
        std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return (false);
    }
    else
    {
        _displayTimestamp();
        std::cout << " index:" << this->_accountIndex;
        std::cout << ";p_amount:" << this->_amount;
        std::cout << ";withdrawal:refused" << std::endl;
        return (true);
    }
}

int Account::checkAmount(void) const
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount << std::endl;
    return (this->_amount);
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp(void)
{
    time_t tim = time(0);
	tm *local_time = localtime(&tim);
	std::cout << "[" << local_time->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_mday << "_";
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_sec << "]";
}