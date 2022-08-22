#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	_name("Nobody Owens"),
	_hit_points(10),
	_energy_point(10),
	_attack_damage(0) {
	return ;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_hit_points(10),
	_energy_point(10),
	_attack_damage(0) {
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	// TODO
}

ClapTrap::~ClapTrap(void) {
	return ;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const & src) {
	// TODO
}
