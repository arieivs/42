#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void) {
	const Animal*		meta = new Animal();
	const Animal*		rex = new Dog();
	const Animal*		garfield = new Cat();
	const WrongAnimal*	fake_garfield = new WrongCat();
	
	std::cout << std::endl << "Meta is an " << meta->getType()
			  << " and it does ";
	meta->makeSound();
	std::cout << "Rex is a " << rex->getType()
			  << " and it does ";
	rex->makeSound();
	std::cout << "Garfield is a " << garfield->getType()
			  << " and it does ";
	garfield->makeSound();
	std::cout << "Wannabe Garfield is a "
			  << fake_garfield->getType() << " and it does ";
	fake_garfield->makeSound();
	
	std::cout << std::endl;
	delete meta;
	delete rex;
	delete garfield;
	delete fake_garfield;

	return 0;
}
