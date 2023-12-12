/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:39:02 by geshin            #+#    #+#             */
/*   Updated: 2023/12/12 18:46:57 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

}

Account::Account(int initial_deposit)
{
	_nbDeposits = initial_deposit;
}

Account::~Account()
{
	//__noop;
}


void Account::makeDeposit(int deposit)
{

}

bool Account::makeWithdrawal(int withdrawal)
{

}

int Account::checkAmount() const
{
	return _amount;
}

void Account::displayStatus() const
{
	
}

void Account::_displayTimestamp()
{
	
}

Account::Account()
{
	
}