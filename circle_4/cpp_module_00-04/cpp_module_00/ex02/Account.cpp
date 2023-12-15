/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:39:02 by geshin            #+#    #+#             */
/*   Updated: 2023/12/15 17:04:19 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>
#include "Account.hpp"

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

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
	std::cout
		<< " "
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;

	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	
	_nbDeposits = 0;
	
	_nbWithdrawals = 0;
	
	_displayTimestamp();
	std::cout
		<< " "
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created"
		<< std::endl;
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;

	_displayTimestamp();
	std::cout
		<< " "
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed"
		<< std::endl;
}


void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	
	_amount += deposit;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout
		<< " "
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount - deposit << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits
		<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout
		<< " "
		<< "index:" << _accountIndex << ";";

	if (_amount < withdrawal)
	{
		std::cout
			<< "p_amount:" << _amount << ";"
			<< "withdrawal:" << "refused"
			<< std::endl;
		return false;
	}

	_nbWithdrawals++;
	_totalNbWithdrawals++;

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	
	std::cout
		<< "p_amount:" << _amount + withdrawal << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	return true;
}

int Account::checkAmount() const
{
	return _amount;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	
	std::cout
		<< " "
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals
		<< std::endl;
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

}