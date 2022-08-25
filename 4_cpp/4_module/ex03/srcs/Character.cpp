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

/* assuming materia can only be ice or cure, no other options */
Character&	Character::operator=(Character const & src) {
	int	i;

	std::cout << "Character copy assignment operator" << std::endl;
	_name = src._name;
	for (i = 0; i < _occupied_slots; i++)
		delete _inventory[i];
	_occupied_slots = src._occupied_slots;
	for (i = 0; i < _occupied_slots; i++) {
		if (src._inventory[i]->getType() == "ice")
			_inventory[i] = new Ice();
		else
			_inventory[i] = new Cure();
	}
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
	(void)idx;
	// I don't understand what they want from me
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= _occupied_slots)
		return ;
	_inventory[idx]->use(target);
}

