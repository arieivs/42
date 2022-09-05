#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
	{
		/* SUBJECT */
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
		
		/* UNEQUIP */
		me->unequip(0);
		std::cout << "Unequiped" << std::endl;
		me->use(0, *bob);
		std::cout << "Tried to use unexistent" << std::endl;
		//me->equip(tmp);
		//std::cout << "Equiped again" << std::endl;
		//me->use(0, *bob);
		std::cout << std::endl;

		delete bob;
		delete me;
		delete src;
		std::cout << std::endl << std::endl;
	}
	{
		/* MINE */
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
		std::cout << std::endl << std::endl;
	}
	{
		/* Areias */
		AMateria *temp = new Ice;
		AMateria *tempi = new Cure;
		std::string basic = "main";
		std::string interf = "inter";
		Character quirky(basic);
		Character inter(interf);

		AMateria *other = temp->clone();
		quirky.equip(temp);
		quirky.use(0, inter);
		inter = quirky;
		inter.use(0, quirky);

		Character mats(quirky);
		mats.use(0, quirky);
		mats.equip(tempi);
		mats.use(1, inter);

		delete temp;
		delete tempi;
		delete other;
	}
	return (0);
}
