#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
	{
		/* SUBJECT */
		std::cout << "SUBJECT TESTS" << std::endl;
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
		delete src;
		std::cout << std::endl << std::endl;
	}
	{
		/* MINE */
		std::cout << "ADDITIONAL TESTS" << std::endl;
		Character		alice("alice");
		MateriaSource	src;
		AMateria*		tmp;
		std::cout << std::endl;

		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		std::cout << std::endl;

		tmp = src.createMateria("ice");
		alice.equip(tmp);
		std::cout << std::endl;

		/* DEEP COPIES */
		Character	alicia(alice);
		alicia.use(0, alice);
		std::cout << std::endl;

		MateriaSource	other_src(src);
		tmp = other_src.createMateria("cure");
		alice.equip(tmp);
		alice.use(1, alicia);
		std::cout << std::endl;

		/* UNEQUIP */
		alice.unequip(0);
		std::cout << "Unequiped" << std::endl;
		alice.use(0, alicia);
		std::cout << "Tried to use unexistent" << std::endl;
		alice.equip(tmp);
		std::cout << "Equiped again" << std::endl;
		alice.use(0, alicia);
		std::cout << std::endl;
	}
	/* There might be a leak
	 * createMateria allocates memory in heap and returns it
	 * thus it sometimes complains when I don't delete tmp's
	 * but fsanitize=address and valgrind don't agree on what the solution should be
	 */
	return (0);
}
