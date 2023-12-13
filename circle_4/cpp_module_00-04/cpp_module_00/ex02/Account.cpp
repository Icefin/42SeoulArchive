/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:39:02 by geshin            #+#    #+#             */
/*   Updated: 2023/12/12 19:32:29 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>
#include "Account.hpp"

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << '\n';
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;

	_amount = initial_deposit;
	_totalAmount += _amount;
	
	_nbDeposits = initial_deposit;
	_totalNbDeposits += _nbDeposits;
	
	_nbWithdrawals = 0;
}

Account::~Account()
{
	_displayTimestamp();
	
}


void Account::makeDeposit(int deposit)
{
	_nbDeposits = deposit;
	_totalNbDeposits += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_nbWithdrawals = withdrawal;
	_totalNbWithdrawals += withdrawal;
}

int Account::checkAmount() const
{
	return _amount;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	
}

void Account::_displayTimestamp()
{
	time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);

	int year = t->tm_year;
	int mon = t->tm_mon;
	int date = t->tm_mday;
	int hour = t->tm_hour;
	int min = t->tm_min;
	int sec = t->tm_sec;

	std::cout << '[' << year << mon << date << '_' << hour << min << sec << "] ";
}

Account::Account()
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}