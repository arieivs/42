#include "SpellBook.hpp"

SpellBook::SpellBook(void) {}

SpellBook::~SpellBook(void) {
	for (unsigned int i = 0; i < spells.size(); i++)
		delete spells[i];
}

void	SpellBook::learnSpell(ASpell* spell) {
	spells.push_back(spell->clone());
}

void	SpellBook::forgetSpell(std::string const & spell_name) {
	for (unsigned int i = 0; i < spells.size(); i++) {
		if (spells[i]->getName() == spell_name) {
			delete spells[i];
			spells.erase(spells.begin() + i);
			break ;
		}
	}
}

ASpell*	SpellBook::createSpell(std::string const & spell_name) {
	for (unsigned int i = 0; i < spells.size(); i++) {
		if (spells[i]->getName() == spell_name) {
			return (spells[i]->clone());
		}
	}
	return (NULL);
}