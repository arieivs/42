#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed") {};

Fwoosh::Fwoosh(Fwoosh const & src) : ASpell(src) {};

Fwoosh&	Fwoosh::operator=(Fwoosh const & src) {
	name = src.getName();
	effects = src.getEffects();
	return (*this);
}

~Fwoosh::Fwoosh(void) {};

ASpell*	Fwoosh::clone(void) const {
	ASpell*	fwoosh = new Fwoosh();
	return (fwoosh);
}