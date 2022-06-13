#include "Zombie.hpp"

int	main(void)
{
	Zombie	*frankie;
	//Zombie	*jason = new Zombie("Jason");

	frankie = newZombie("Frankie");
	frankie->announce();
	delete frankie;
	return (0);
}