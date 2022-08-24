#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	std::cout << "Dog default constructor" << std::endl;
	type = "Dog";
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
	return ;
}

void	Dog::makeSound(void) const {
	std::cout << "Auf auf!" << std::endl;
}

