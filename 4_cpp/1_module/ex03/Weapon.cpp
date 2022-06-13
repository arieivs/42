#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {
	std::cout << "Weapon " << type << " created" << std::endl;
}

Weapon::~Weapon(void) {
	std::cout << "Weapon " << _type << " destroyed" << std::endl;
}

std::string const &	Weapon::getType(void) const
{
	std::string const &	typeRef = _type;

	return (typeRef);
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
}