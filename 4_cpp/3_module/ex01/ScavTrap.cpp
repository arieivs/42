#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
	_name("Nobody Owens"),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0) {
	std::cout << "ScavTrap Default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) :
	_name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0) {
	std::cout << "ScavTrap Parameterized constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) {
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Destructor called" << std::endl;
	return ;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const & src) {
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return (*this);
}
