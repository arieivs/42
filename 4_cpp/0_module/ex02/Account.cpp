#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* Datetime in C++
 * check tm struct: https://en.cppreference.com/w/cpp/chrono/c/tm
 */
void	Account::_displayTimestamp(void)
{
	std::time_t	now;
	std::tm		*now_local;

	now = std::time(0);
	now_local = std::localtime(&now);
	std::cout << "[" << (now_local->tm_year + 1900)
			  << std::setfill('0') << std::setw(2) << (now_local->tm_mon + 1)
			  << std::setfill('0') << std::setw(2) << (now_local->tm_mday) << "_"
			  << std::setfill('0') << std::setw(2) << (now_local->tm_hour)
			  << std::setfill('0') << std::setw(2) << (now_local->tm_min)
			  << std::setfill('0') << std::setw(2) << (now_local->tm_sec) << "] ";
	/* for making it easier to compare with the logs: */
	/*std::cout << "[19920104_091532] ";*/
}

Account::Account(int initial_deposit):
	_accountIndex(Account::_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount << ";" << "created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount << ";" << "closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";"
			  << "total:" << Account::_totalAmount << ";"
			  << "deposits:" << Account::_totalNbDeposits << ";"
			  << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount << ";"
			  << "deposits:" << this->_nbDeposits << ";"
			  << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << this->_amount << ";"
			  << "deposit:" << deposit << ";";
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << "amount:" << this->_amount << ";"
			  << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << this->_amount << ";"
			  << "withdrawal:";
	if (this->_amount < deposit)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	this->_amount -= deposit;
	Account::_totalAmount -= deposit;
	std::cout << deposit << ";"
			  << "amount:" << this->_amount << ";"
			  << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

