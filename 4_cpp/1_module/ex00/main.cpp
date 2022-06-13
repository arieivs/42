#include "Zombie.hpp"

int	main(void)
{
	Zombie	*frankie;

	frankie = newZombie("Frankie");
	frankie->announce();
	delete frankie;
	randomChump("Zed");
	return (0);
}