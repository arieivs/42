#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor" << std::endl;
	return ;
}

Brain::Brain(Brain const & src) {
	std::cout << "Brain copy constructor" << std::endl;
	*this = src;
	return ;
}

Brain&	Brain::operator=(Brain const & src) {
	int	i;

	std::cout << "Brain copy assignment operator" << std::endl;
	for (i = 0; i < 100; i++)
		ideas[i] = src.ideas[i]; 
	return (*this);
}

Brain::~Brain(void) {
	std::cout << "Brain destructor" << std::endl;
	return ;
}

