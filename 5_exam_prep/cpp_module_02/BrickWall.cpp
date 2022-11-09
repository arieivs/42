#include "BrickWall.hpp"

BrickWall::BrickWall(void) : ATarget("Inconspicuous Red-brick Wall") {};

BrickWall::BrickWall(BrickWall const & src) : ATarget(src) {};

BrickWall&	BrickWall::operator=(BrickWall const & src) {
	type = src.getType();
	return (*this);
}

BrickWall::~BrickWall(void) {};

ATarget*	BrickWall::clone(void) const {
	ATarget*	brick_wall = new BrickWall();
	return (brick_wall);
}