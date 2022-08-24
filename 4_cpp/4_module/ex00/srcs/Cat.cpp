#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "Cat default constructor" << std::endl;
	type = "Cat";
	return ;
}

Cat::Cat(Cat const & src) {
	std::cout << "Cat copy constructor" << std::endl;
	type = src.type;
	return ;
}

Cat&	Cat::operator=(Cat const & src) {
	std::cout << "Cat copy assignment operator" << std::endl;
	type = src.type;
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "Cat destructor" << std::endl;
	return ;
}

void	Cat::makeSound(void) const {
	std::cout << "Miauuuu..." << std::endl;
}

