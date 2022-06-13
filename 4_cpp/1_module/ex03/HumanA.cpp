#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon):
	name(name),
	weapon(weapon)
{
	std::cout << "Human " << name << " created" << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << "Human " << name << " destroyed" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
