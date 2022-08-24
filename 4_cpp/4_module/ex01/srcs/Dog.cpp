#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	std::cout << "Dog default constructor" << std::endl;
	type = "Dog";
	brain = new Brain();
	return ;
}

Dog::Dog(Dog const & src) {
	std::cout << "Dog copy constructor" << std::endl;
	*this = src;
	return ;
}

Dog&	Dog::operator=(Dog const & src) {
	std::cout << "Dog copy assignment operator" << std::endl;
	type = src.type;
	brain = new Brain(*src.brain);
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "Dog destructor" << std::endl;
	delete brain;
	return ;
}

void	Dog::makeSound(void) const {
	std::cout << "Auf auf!" << std::endl;
}

std::string	Dog::getIdea(int i) const {
	return brain->getIdea(i);
}

void	Dog::setIdea(int i, std::string idea) {
	brain->setIdea(i, idea);
}

