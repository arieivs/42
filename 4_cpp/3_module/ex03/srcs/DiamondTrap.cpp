#include "DiamondTrap.hpp"

/* this->FragTrap::_hit_points = FragTrap::_hit_points */
DiamondTrap::DiamondTrap(void) :
	ClapTrap("Nobody Owens_clap_name"),
	ScavTrap(),
	FragTrap() {
	this->_name = "Nobody Owens";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap Default Constructor was called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(),
	FragTrap() {
	this->_name = name;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap Parameterized Constructor was called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) {
	*this = src;
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap Destructor was called" << std::endl;
	return ;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const & src) {
	ClapTrap::operator=(src);
	this->_name = src._name;
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "I am " << this->_name << " - " << ClapTrap::_name << std::endl;
}

