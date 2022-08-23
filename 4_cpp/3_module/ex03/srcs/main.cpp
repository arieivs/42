#include "DiamondTrap.hpp"

int	main(void) {
	std::cout << "CONSTRUCTORS" << std::endl;
	DiamondTrap	quimera = DiamondTrap("Quimera");
	DiamondTrap	frankenstein = DiamondTrap("Frankenstein");

	std::cout << std::endl << "ATTACK AND MORE" << std::endl;
	quimera.attack("Frankenstein");
	frankenstein.takeDamage(quimera.getAttackDamage());
	frankenstein.beRepaired(5);
	quimera.whoAmI();
	quimera.guardGate();
	frankenstein.whoAmI();
	frankenstein.highFivesGuys();

	std::cout << std::endl << "COPY CONSTRUCTORS" << std::endl;
	DiamondTrap	quimera2 = DiamondTrap(quimera);
	DiamondTrap	frankenstein2;

	frankenstein2 = frankenstein;
	quimera2.whoAmI();
	frankenstein2.whoAmI();

	std::cout << std::endl << "DESTRUCTORS" << std::endl;
	return (0);
}
