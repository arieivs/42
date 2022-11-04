#include "Warlock.hpp"

/*
 * Sad reality: there are no built-in man pages for C++...
 * so I guess I just need to memorize it if I want to use std::vector
 *
 * vector.push_back(element)
 * vector.clear() -> destroys all elements, vector is left with size 0
 * vector.erase(iterator) -> e.g. vec.erase(vec.begin() + 5)
 */

Warlock::Warlock(std::string name, std::string title) :
	name(name),
	title(title) {
	std::cout << name << ": This looks like another boring day."
			  << std::endl;
}

Warlock::~Warlock(void) {
	spells.clear(); // is this necessary?
	std::cout << name << ": My job here is done!" << std::endl;
}

std::string const &	Warlock::getName(void) const {
	return (name);
}

std::string const &	Warlock::getTitle(void) const {
	return (title);
}

void	Warlock::setTitle(std::string const & new_title) {
	title = new_title;
}

void	Warlock::introduce() const {
	std::cout << name << ": I am " << name << ", " << title << "!"
			  << std::endl;
}

void	Warlock::learnSpell(ASpell* spell) {
	spells.push_back(spell->clone());
}

void	Warlock::forgetSpell(std::string spell_name) {
	for (unsigned int i = 0; i < spells.size(); i++) {
		if (spells[i]->getName() == spell_name) {
			spells.erase(spells.begin() + i);
			break ;
		}
	}
}

void	Warlock::launchSpell(std::string spell_name, ATarget& target) {
	for (unsigned int i = 0; i < spells.size(); i++) {
		if (spells[i]->getName() == spell_name) {
			spells[i]->launch(target);
			break ;
		}
	}
}




