#include "Zombie.hpp"

int	main(void)
{
	Zombie	frankie = Zombie("Frankie");
	Zombie	*jason = new Zombie("Jason");

	frankie.announce();
	jason->announce();
	delete jason;
	return (0);
}