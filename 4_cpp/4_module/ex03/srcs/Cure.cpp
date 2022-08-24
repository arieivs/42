#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Cure default constructor" << std::endl;
	return ;
}

Cure::Cure(Cure const & src) : AMateria ("cure") {
	std::cout << "Cure copy constructor" << std::endl;
	return ;
}

Cure&	Cure::operator=(Cure const & src) {
	std::cout << "Cure copy assignment operator" << std::endl;
	type = "cure";
	return (*this);
}

Cure::~Cure(void) {
	std::cout << "Cure destructor" << std::endl;
	return ;
}

Cure*	clone(void) const {
	Cure*	cure_clone = new Cure();

	return (cure_clone);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName()
			  << "'s wounds *" << std::endl;
}

