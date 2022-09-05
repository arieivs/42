#include "Character.hpp"

Character::Character(void) :
	_name("Nobody Owens"),
	_used_inventory(0) {
	std::cout << "Character default constructor" << std::endl;
	for (int i = 0; i < INVENTORY_SPACE; i++)
		_inventory[i] = 0;
	return ;
}

Character::Character(std::string name) :
	_name(name),
	_used_inventory(0) {
	std::cout << "Character parameterized constructor" << std::endl;
	for (int i = 0; i < INVENTORY_SPACE; i++)
		_inventory[i] = 0;
	return ;
}

/* assuming materia can only be ice or cure, no other options
 * chose not to copy unequiped materia, didn't seem very useful
 */
Character::Character(Character const & src) :
	_name(src._name),
	_used_inventory(0) {
	std::cout << "Character copy constructor" << std::endl;
	for (int i = 0; i < INVENTORY_SPACE; i++) {
		if (src._inventory[i] && src._inventory[i]->getType() == "ice")
			_inventory[i] = new Ice();
		else if (src._inventory[i] && src._inventory[i]->getType() == "cure")
			_inventory[i] = new Cure();
		else
			_inventory[i] = 0;
	}
	return ;
}

Character&	Character::operator=(Character const & src) {
	int				i;
	AMateriaList*	to_delete;

	std::cout << "Character copy assignment operator" << std::endl;
	_name = src._name;
	/* deleting/resetting inventory */
	for (i = 0; i < INVENTORY_SPACE; i++) {
		if (_inventory[i] != 0)
			delete _inventory[i];
		_inventory[i] = 0;
	}
	/* copying inventory */
	for (i = 0; i < INVENTORY_SPACE; i++) {
		if (src._inventory[i] && src._inventory[i]->getType() == "ice")
			_inventory[i] = new Ice();
		else if (src._inventory[i] && src._inventory[i]->getType() == "cure")
			_inventory[i] = new Cure();
	}
	/* deleting used inventory */
	while (_used_inventory) {
		to_delete = _used_inventory;
		_used_inventory = _used_inventory->next;
		delete to_delete->used_materia;
		delete to_delete;
	}
	/* resetting used inventory (not worth copying it) */
	_used_inventory = 0;
	return (*this);
}

Character::~Character(void) {
	int				i;
	AMateriaList*	to_delete;
	
	std::cout << "Character destructor" << std::endl;
	for (i = 0; i < INVENTORY_SPACE; i++) {
		if (_inventory[i] != 0)
			delete _inventory[i];
	}
	while (_used_inventory) {
		to_delete = _used_inventory;
		_used_inventory = _used_inventory->next;
		delete to_delete->used_materia;
		delete to_delete;
	}
	return ;
}

std::string const &	Character::getName(void) const {
	return _name;
}

void	Character::equip(AMateria* m) {
	int	i;

	i = first_free_slot();
	if (i == -1)
		return ;
	_inventory[i] = m;
}

void	Character::unequip(int idx) {
	AMateriaList*	unequiped = new AMateriaList;
	
	if (idx < 0 || idx >= INVENTORY_SPACE || !_inventory[idx])
		return ;
	unequiped->used_materia = _inventory[idx];
	unequiped->next = _used_inventory; /* set to 0 at the beginning */
	_used_inventory = unequiped;
	_inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= INVENTORY_SPACE || !_inventory[idx])
		return ;
	_inventory[idx]->use(target);
}

int	Character::first_free_slot(void) {
	int	i;

	for (i = 0; i < INVENTORY_SPACE; i++) {
		if (!_inventory[i])
			return (i);
	}
	return (-1);
}
