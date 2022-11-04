#include "ATarget.hpp"

ATarget::ATarget(void) : type("undefined") {};

ATarget::ATarget(std::string type) : type(type) {};

ATarget::ATarget(ATarget const & src) : type(src.getType()) {};

ATarget&	ATarget::operator=(ATarget const & src) {
	type = getType();
	return (*this);
}

~ATarget::ATarget(void) {};

std::string	ATarget::getType(void) const {
	return type;
}

void	ATarget::getHitBySpell(ASpell const & spell) {
	std::cout << type << " has been " << spell->getEffects() << "!"
			  << std::endl;
}