#include "Polymorph.hpp"

Polymorph::Polymorph(void) : ASpell("Polymorph", "turned into a critter") {};

Polymorph::Polymorph(Polymorph const & src) : ASpell(src) {};

Polymorph&	Polymorph::operator=(Polymorph const & src) {
	name = src.getName();
	effects = src.getEffects();
	return (*this);
}

Polymorph::~Polymorph(void) {};

ASpell*	Polymorph::clone(void) const {
	ASpell*	polymorph = new Polymorph();
	return (polymorph);
}