#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
	std::cout << "WrongAnimal copy constructor" << std::endl;
	type = src.type;
	return ;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const & src) {
	std::cout << "WrongAnimal copy assignment operator" << std::endl;
	type = src.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor" << std::endl;
	return ;
}

std::string	WrongAnimal::getType(void) const {
	return type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "*generic animal sound*" << std::endl;
}

