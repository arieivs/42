#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
	std::cout << "Animal default constructor" << std::endl;
	return ;
}

Animal::Animal(Animal const & src) {
	std::cout << "Animal copy constructor" << std::endl;
	type = src.type;
	return ;
}

Animal&	Animal::operator=(Animal const & src) {
	std::cout << "Animal copy assignment operator" << std::endl;
	type = src.type;
	return (*this);
}

Animal::~Animal(void) {
	std::cout << "Animal destructor" << std::endl;
	return ;
}

std::string	Animal::getType(void) const {
	return type;
}

void	Animal::makeSound(void) const {
	std::cout << "*generic animal sound*" << std::endl;
}

