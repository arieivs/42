#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	_name("Nobody Owens"),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0) {
	std::cout << "ClapTrap Parameterized constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Destructor called" << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const & src) {
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	return (*this);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return this->_attack_damage;
}

bool	ClapTrap::hasVitals(void) {
	if (this->_energy_points <= 0) {
		std::cout << "ClapTrap " << this->_name
				  << " ran out of energy points..." << std::endl;
		return (false);
	}
	if (this->_hit_points <= 0) {
		std::cout << "ClapTrap " << this->_name
				  << " ran out of hit points..." << std::endl;
		return (false);
	}
	return (true);
}

void	ClapTrap::attack(const std::string& target) {
	if (!this->hasVitals())
		return ;
	this->_energy_points -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attack_damage << " points of damage!"
			  << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points <= 0) {
		std::cout << "ClapTrap " << this->_name << " was already dead."
				  << std::endl;
		return ;
	}
	this->_hit_points = this->_hit_points < amount ? 0 : this->_hit_points - amount;
	std::cout << "ClapTrap " << this->_name << " lost " << amount
			  << " hit points, " << this->_hit_points << " hit points left."
			  << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->hasVitals())
		return ;
	this->_energy_points -= 1;
	this->_hit_points += amount;
	std::cout << "ClapTrap " << this->_name << " won " << amount
			  << " hit points, it has " << this->_hit_points << " hit points now."
			  << std::endl;
}

