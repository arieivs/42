#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	std::cout << "WrongCat default constructor" << std::endl;
	type = "WrongCat";
	return ;
}

WrongCat::WrongCat(WrongCat const & src) {
	std::cout << "WrongCat copy constructor" << std::endl;
	type = src.type;
	return ;
}

WrongCat&	WrongCat::operator=(WrongCat const & src) {
	std::cout << "WrongCat copy assignment operator" << std::endl;
	type = src.type;
	return (*this);
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor" << std::endl;
	return ;
}

void	WrongCat::makeSound(void) const {
	std::cout << "Miauuuu..." << std::endl;
}

