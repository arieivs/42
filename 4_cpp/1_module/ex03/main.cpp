#include "Weapon.hpp"

int	main(void)
{
	Weapon	sword = Weapon("sword");
	Weapon	axe = Weapon("axe");

	std::cout << sword.getType() << std::endl;
	std::cout << axe.getType() << std::endl;
	sword.setType("dagger");
	std::cout << sword.getType() << std::endl;
	return (0);
}