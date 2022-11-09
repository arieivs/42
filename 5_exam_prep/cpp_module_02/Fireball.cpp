#include "Fireball.hpp"

Fireball::Fireball(void) : ASpell("Fireball", "burnt to a crisp") {};

Fireball::Fireball(Fireball const & src) : ASpell(src) {};

Fireball&	Fireball::operator=(Fireball const & src) {
	name = src.getName();
	effects = src.getEffects();
	return (*this);
}

Fireball::~Fireball(void) {};

ASpell*	Fireball::clone(void) const {
	ASpell*	fireball = new Fireball();
	return (fireball);
}