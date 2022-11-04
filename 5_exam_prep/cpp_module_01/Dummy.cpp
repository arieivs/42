#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Target Practice Dummy") {};

Dummy::Dummy(Dummy const & src) : ATarget(src) {};

Dummy&	Dummy::operator=(Dummy const & src) {
	type = src.getType();
	return (*this);
}

Dummy::~Dummy(void) {};

ATarget*	Dummy::clone(void) const {
	ATarget*	dummy = new Dummy();
	return (dummy);
}