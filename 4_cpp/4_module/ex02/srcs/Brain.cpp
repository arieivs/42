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
	for (i = 0; i < NR_IDEAS; i++)
		ideas[i] = src.ideas[i]; 
	return (*this);
}

Brain::~Brain(void) {
	std::cout << "Brain destructor" << std::endl;
	return ;
}

std::string*	Brain::getIdeas(void) {
	return ideas;
}

std::string	Brain::getIdea(int i) const {
	if (i < 0 || i >= NR_IDEAS)
		return NULL;
	return ideas[i];
}

void	Brain::setIdea(int i, std::string idea) {
	if (i < 0 || i >= NR_IDEAS)
		return ;
	ideas[i] = idea;
}

