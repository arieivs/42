#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	std::cout << "Dog default constructor" << std::endl;
	type = "Dog";
	brain = new Brain();
	return ;
}

Dog::Dog(Dog const & src) {
	std::cout << "Dog copy constructor" << std::endl;
	type = src.type;
	return ;
}

Dog&	Dog::operator=(Dog const & src) {
	std::cout << "Dog copy assignment operator" << std::endl;
	type = src.type;
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
	if (i < 0 || i >= 100)
		return NULL;
	return brain->ideas[i];
}

void	Dog::setIdea(int i, std::string idea) {
	if (i < 0 || i >= 100)
		return ;
	brain->ideas[i] = idea;
}

