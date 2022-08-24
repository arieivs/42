#include "AMateria.hpp"

AMateria::AMateria(void) : type("") {
	std::cout << "Materia default constructor" << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type) : type(type) {
	std::cout << "Materia parameterized constructor" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const & src) {
	std::cout << "Materia copy constructor" << std::endl;
	if (type == "" && src.type != "")
		type = src.type;
	return ;
}

AMateria&	AMateria::operator=(AMateria const & src) {
	std::cout << "Materia copy assignment operator" << std::endl;
	if (type == "" && src.type != "")
		type = src.type;
	return (*this);
}

AMateria::~AMateria(void) {
	std::cout << "Materia destructor" << std::endl;
	return ;
}

std::string const &	AMateria::getType(void) const {
	return type;
}

void	AMateria::use(ICharacter& target) {
	std::cout << "* a mystery materia is being used on "
			  << target.getName() << " *" << std::endl;
}

