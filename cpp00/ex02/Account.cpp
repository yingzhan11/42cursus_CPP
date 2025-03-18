/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:42:42 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/17 14:42:44 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

// Initial static var
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/**
 * Constructor & Destructor
 */
// Create and display accouts
Account::Account(int initial_deposit)
{
	// Initialize account info
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	// Update account nbr and amount
	_nbAccounts++;
	_totalAmount += _amount;
	// Display account
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

/**
 * Public functions
 */
// Display all accounts info
void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Displaye the status of an account
void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	pAmount = _amount;

	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << pAmount
		<< ";deposit:" << deposit << ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int pAmount = _amount;

	if (withdrawal <= pAmount)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
	}
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << pAmount << ";withdrawal:";
	if (withdrawal <= pAmount)
	{
		std::cout << withdrawal << ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << "refused\n";
		return (false);
	}
}

// Other functions
int		Account::checkAmount() const
{
	return (_amount);
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

/**
 * Private functions
 */
// Display the timeStamp
void	Account::_displayTimestamp()
{
	// Get system time in seconds
	std::time_t	currentTime = std::time(NULL);
	// Convert system time to local time in (y,m,d,h,m,s format)
	std::tm* localTime = std::localtime(&currentTime);
	// Convert time to string and display it
	char timeStr[100];
	std::strftime(timeStr, sizeof(timeStr), "%Y%m%d_%H%M%S", localTime);
	std::cout << "[" << timeStr << "]";
}