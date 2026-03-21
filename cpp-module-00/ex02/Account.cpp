#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::_displayTimestamp(void) {
    std::time_t now = std::time(nullptr);
    char buf[20];
    if (std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", std::localtime(&now))) {
        std::cout << buf;
    }
}

/*								getters									*/

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void ) 
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) 
{ 
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() <<
		";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

/*								setters									*/

void	Account::makeDeposit( int deposit )
{
	_totalNbDeposits++;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "indexs:" << _accountIndex << ";p_amount:" << _amount <<";deposit:" << deposit
		<< ";amount:"<< _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > checkAmount())
	{
		_displayTimestamp();
		std::cout << "indexs:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused"<< std::endl;
		return (false);
	}
	else
	{
		_nbWithdrawals++;
		_displayTimestamp();
		std::cout << "indexs:" << _accountIndex << ";p_amount:" << _amount <<
			";withdrawal:" << withdrawal << ";amount:"<< _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals<< std::endl;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

	}
	return (true);
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << 
		";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

