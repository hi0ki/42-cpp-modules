#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	typedef void (Harl::*PtrToFt)(void);
	PtrToFt Arrfunts[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string lvls[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if (level == lvls[i])
		{
			(this->*Arrfunts[i])();
			return ;
		}
	}
	std::cerr << "ERROR: Can't find this level\n";
}