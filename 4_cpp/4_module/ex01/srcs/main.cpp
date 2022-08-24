#include "Dog.hpp"
#include "Cat.hpp"

int	main(void) {
	const Animal*		meta = new Animal();
	const Animal*		rex = new Dog();
	const Animal*		garfield = new Cat();
	
	std::cout << std::endl << "Meta is an " << meta->getType()
			  << " and it does ";
	meta->makeSound();
	std::cout << "Rex is a " << rex->getType()
			  << " and it does ";
	rex->makeSound();
	std::cout << "Garfield is a " << garfield->getType()
			  << " and it does ";
	garfield->makeSound();
	
	std::cout << std::endl;
	delete meta;
	delete rex;
	delete garfield;

	return 0;
}
