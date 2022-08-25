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

MateriaSource&	MateriaSource::operator=(MateriaSource const & src) {
	int	i;

	std::cout << "MateriaSource copy assignment operator" << std::endl;
	for (i = 0; i < _occupied_slots; i++)
		delete _inventory[i];
	_occupied_slots = src.occupied_slots;
	for (i = 0; i < _occupied_slots; i++)
		_inventory[i] = new AMateria(src._inventory[i]->getType());
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
	// TODO
}

