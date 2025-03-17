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
 * Constructor
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
	std::cout << " index:" << _accountIndex << ";amout:" << _amount << ";created\n";
}

/**
 * Public functions
 */
//makeDeposit

//makeWithdrawal

//checkAmount

//displayStatus


/**
 * Private functions
 */
//_displayTimestamp
void	Account::_displayTimestamp()
{
	std::time_t	currentTime = std::time(NULL);
}