#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
	IMateriaSource*	src = new MateriaSource();
	ICharacter*	me = new Character("me");
	AMateria*	tmp;
	ICharacter* bob = new Character("bob");
	std::cout << std::endl;
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	
	delete bob;
	delete me;
	std::cout << std::endl;
	delete src;
	
	return (0);
}
