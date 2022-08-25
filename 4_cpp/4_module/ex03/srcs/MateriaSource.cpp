#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _occupied_slots(0) {
	std::cout << "MateriaSource default constructor" << std::endl;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	std::cout << "MateriaSource copy constructor" << std::endl;
	*this = src;
	return ;
}

/* assuming materia can only be ice or cure, no other options */
MateriaSource&	MateriaSource::operator=(MateriaSource const & src) {
	int	i;

	std::cout << "MateriaSource copy assignment operator" << std::endl;
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

MateriaSource::~MateriaSource(void) {
	int	i;
	
	std::cout << "MateriaSource destructor" << std::endl;
	for (i = 0; i < _occupied_slots; i++)
		delete _inventory[i];
	return ;
}

void	MateriaSource::learnMateria(AMateria* m) {
	if (_occupied_slots >= INVENTORY_SPACE)
		return ;
	_inventory[_occupied_slots] = m;
	_occupied_slots++;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	int	i;

	for (i = 0; i < _occupied_slots; i++) {
		if (_inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return (0);
}

