#include "Character.hpp"

Character::Character(void) :
	_name("Nobody Owens"),
	_occupied_slots(0) {
	std::cout << "Character default constructor" << std::endl;
	return ;
}

Character::Character(std::string name) :
	_name(name),
	_occupied_slots(0)  {
	std::cout << "Character parameterized constructor" << std::endl;
	return ;
}

Character::Character(Character const & src) {
	std::cout << "Character copy constructor" << std::endl;
	*this = src;
	return ;
}

Character&	Character::operator=(Character const & src) {
	int	i;

	std::cout << "Character copy assignment operator" << std::endl;
	_name = src.name;
	for (i = 0; i < _occupied_slots; i++)
		delete _inventory[i];
	_occupied_slots = src.occupied_slots;
	for (i = 0; i < _occupied_slots; i++)
		_inventory[i] = new AMateria(src._inventory[i]->getType());
	return (*this);
}

Character::~Character(void) {
	int	i;
	
	std::cout << "Character destructor" << std::endl;
	for (i = 0; i < _occupied_slots; i++)
		delete _inventory[i];
	return ;
}

std::string const &	Character::getName(void) const {
	return _name;
}

void	Character::equip(AMateria* m) {
	if (_occupied_slots >= INVENTORY_SPACE)
		return ;
	_inventory[_occupied_slots] = m;
	_occupied_slots++;
}

void	Character::unequip(int idx) {
	// I don't understand what they want from me
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= _occupied_slots)
		return ;
	if (_inventory[idx].getType() == "ice")
		Ice::use(target);
	else if (_inventory[idx].getType() == "cure")
		Cure::use(target);
	else
		AMateria::use(target);
	// Is there a smarter way to do this?
}
