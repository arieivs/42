#include "Dog.hpp"
#include "Cat.hpp"

int	main(void) {
	std::cout << "TEST ARRAY OF ANIMALS" << std::endl;
	Animal*	noes_arc[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
	int		i;

	std::cout << std::endl;
	for (i = 0; i < 4; i++) {
		std::cout << noes_arc[i]->getType() << " says ";
		noes_arc[i]->makeSound();
	}
	std::cout << std::endl;
	for (i = 0; i < 4; i++) {
		delete noes_arc[i];
	}
	
	std::cout << std::endl << "TEST WE'RE DEEP COPYING" << std::endl;
	Dog*	rex = new Dog();
	//Dog*	max = new Dog(*rex);
	//Dog*	lacie;

	//lacie = rex;
	rex->setIdea(0, "Where did I left that bone?");
	//max->setIdea(0, "I wouldn't know what to do with a cat if I got one");
	std::cout << std::endl << "Rex thinks: " << rex->getIdea(0) << std::endl;
	//std::cout << "Max thinks: " << max->getIdea(0) << std::endl;
	//std::cout << "Lacie thinks: " << lacie->getIdea(0) << std::endl;
	//lacie->setIdea(0, "I need to find my girl!");
	std::cout << "Rex thinks: " << rex->getIdea(0) << std::endl;
	//std::cout << "Lacie thinks: " << lacie->getIdea(0) << std::endl << std::endl;

	delete rex;
	//delete max;

	return 0;
}
