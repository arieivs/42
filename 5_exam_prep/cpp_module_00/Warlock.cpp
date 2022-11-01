#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) :
	name(name),
	title(title) {
	std::cout << name << ": This looks like another boring day."
			  << std::endl;
}

Warlock::~Warlock(void) {
	std::cout << name << ": My job here is done!" << std::endl;
}

std::string const &	Warlock::getName(void) const {
	return (name);
}

std::string const &	Warlock::getTitle(void) const {
	return (title);
}

void	Warlock::setTitle(std::string const & new_title) {
	title = new_title; // need some protection?
}

void	Warlock::introduce() const {
	std::cout << name << ": I am " << name << ", " << title << "!"
			  << std::endl;
}
