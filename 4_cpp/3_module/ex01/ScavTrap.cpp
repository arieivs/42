#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
	ClapTrap() {
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) :
	ClapTrap(name) {
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
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

void	ScavTrap::attack(const std::string& target) {
	if (!this->hasVitals())
		return ;
	this->_energy_points -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attack_damage << " points of damage!"
			  << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " is now in gate keeping mode."
			  << std::endl;
}

