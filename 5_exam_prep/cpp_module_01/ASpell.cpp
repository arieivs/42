#include "ASpell.hpp"

ASpell::ASpell(void) : name("undefined"), effects("nothing") {};

ASpell::ASpell(std::string name, std::string effects) :
	name(name), effects(effects) {};

ASpell::ASpell(ASpell const & src) :
	name(src.getName()), effects(src.getEffects()) {};

ASpell&	ASpell::operator=(ASpell const & src) {
	name = src.getName();
	effects = src.getEffects();
	return (*this);
}

~ASpell::ASpell(void) {};

std::string	ASpell::getName(void) const {
	return name;
}

std::string ASpell::getEffects(void) const {
	return effects;
}

void	ASpell::launch(ATarget const & target) {
	target->getHitBySpell(this);
}
