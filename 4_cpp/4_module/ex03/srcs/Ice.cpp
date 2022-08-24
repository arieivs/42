#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Ice default constructor" << std::endl;
	return ;
}

Ice::Ice(Ice const & src) : AMateria ("ice") {
	std::cout << "Ice copy constructor" << std::endl;
	return ;
}

Ice&	Ice::operator=(Ice const & src) {
	std::cout << "Ice copy assignment operator" << std::endl;
	type = "ice";
	return (*this);
}

Ice::~Ice(void) {
	std::cout << "Ice destructor" << std::endl;
	return ;
}

Ice*	clone(void) const {
	Ice*	ice_clone = new Ice();

	return (ice_clone);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots and ice bolt at "
			  << target.getName() << " *" << std::endl;
}

