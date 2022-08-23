#include "FragTrap.hpp"

FragTrap::FragTrap(void) :
	ClapTrap() {
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) :
	ClapTrap(name) {
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap Parameterized constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src._name) {
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	std::cout << "FragTrap Copy constructor called" << std::endl;
	return ;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Destructor called" << std::endl;
	return ;
}

FragTrap&	FragTrap::operator=(FragTrap const & src) {
	ClapTrap::operator=(src);
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << this->_name << " asks for a high five!" << std::endl;
}

