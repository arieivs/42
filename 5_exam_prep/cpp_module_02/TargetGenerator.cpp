#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) {}

TargetGenerator::~TargetGenerator(void) {
	for (unsigned int i = 0; i < targets.size(); i++)
		delete targets[i];
}

void	TargetGenerator::learnTargetType(ATarget* target) {
	targets.push_back(target->clone());
}

void	TargetGenerator::forgetTargetType(std::string const & target_type) {
	for (unsigned int i = 0; i < targets.size(); i++) {
		if (targets[i]->getType() == target_type) {
			targets.erase(targets.begin() + i);
			break ;
		}
	}
}

ATarget*	TargetGenerator::createTarget(std::string const & target_type) {
	for (unsigned int i = 0; i < targets.size(); i++) {
		if (targets[i]->getType() == target_type) {
			return (targets[i]->clone());
		}
	}
	return (NULL);
}
