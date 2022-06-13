#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL)
{
	std::cout << "Human " << name << " created" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "Human " << this->name << " destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon& newWeapon)
{
	this->weapon = &newWeapon;
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks";
	if (weapon != NULL)
		std::cout << " with their " << weapon->getType();
	std::cout << std::endl;
}
