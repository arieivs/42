#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("Animal") {
	std::cout << "Animal default constructor" << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const & src) {
	std::cout << "Animal copy constructor" << std::endl;
	type = src.type;
	return ;
}

AAnimal&	AAnimal::operator=(AAnimal const & src) {
	std::cout << "Animal copy assignment operator" << std::endl;
	type = src.type;
	return (*this);
}

AAnimal::~AAnimal(void) {
	std::cout << "Animal destructor" << std::endl;
	return ;
}

std::string	AAnimal::getType(void) const {
	return type;
}

