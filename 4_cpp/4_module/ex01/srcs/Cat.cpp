#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "Cat default constructor" << std::endl;
	type = "Cat";
	brain = new Brain();
	return ;
}

Cat::Cat(Cat const & src) {
	std::cout << "Cat copy constructor" << std::endl;
	*this = src;
	return ;
}

Cat&	Cat::operator=(Cat const & src) {
	std::cout << "Cat copy assignment operator" << std::endl;
	type = src.type;
	brain = new Brain(*src.brain);
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "Cat destructor" << std::endl;
	delete brain;
	return ;
}

void	Cat::makeSound(void) const {
	std::cout << "Miauuuu..." << std::endl;
}

std::string	Cat::getIdea(int i) const {
	return brain->getIdea(i);
}

void	Cat::setIdea(int i, std::string idea) {
	brain->setIdea(i, idea);
}

