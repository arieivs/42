#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl is awake" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl went to sleep" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
			  << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn't put enough bacon in my burger! "
			  << "If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I've been coming for years whereas you started working here since last month."
			  << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"debug", "info", "warning", "error"};
	typedef void(Harl::*Complain)();
	Complain	complains[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int			i;

	for (i = 0; i < 4; i++)
	{
		if (levels[i].compare(level) == 0)
		{
			(this->*(complains[i]))();
			break;
		}
	}
}