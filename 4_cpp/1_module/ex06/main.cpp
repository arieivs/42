#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl = Harl();
	
	if (ac != 2)
	{
		std::cout << "One complain at a time please..." << std::endl;
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}