#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) :
	name(name),
	title(title),
	spell_book(new SpellBook()) {
	std::cout << name << ": This looks like another boring day."
			  << std::endl;
}

Warlock::~Warlock(void) {
	delete spell_book;
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
	spell_book->learnSpell(spell);
}

void	Warlock::forgetSpell(std::string spell_name) {
	spell_book->forgetSpell(spell_name);
}

void	Warlock::launchSpell(std::string spell_name, ATarget& target) {
	ASpell*	spell;

	spell = spell_book->createSpell(spell_name);
	if (!spell)
		return ;
	spell->launch(target);
	delete spell;
}
