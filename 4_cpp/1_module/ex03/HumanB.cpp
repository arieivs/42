#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name)
{
	std::cout << "Human " << name << " created" << std::endl;
}

HumanB::~HumanB(void) {
	std::cout << "Human " << this->name << " destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon& newWeapon)
{
	this->weapon = &newWeapon;
}

/*
Do not call attack() on a HumanB without a weapon
Checking if a member variable has been initialised doesn't seem to be easy in C98
*/
void	HumanB::attack(void)
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
