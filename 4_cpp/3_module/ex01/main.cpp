#include "ScavTrap.hpp"

int	main(void) {
	std::cout << "CONSTRUCTORS" << std::endl;
	ScavTrap	hodor = ScavTrap("Hodor");
	ScavTrap	gate_keeper = ScavTrap("Gate Keeper");

	std::cout << std::endl << "ATTACK AND GUARD" << std::endl;
	hodor.attack("Gate Keeper");
	gate_keeper.takeDamage(hodor.getAttackDamage());
	gate_keeper.beRepaired(5);
	gate_keeper.guardGate();

	std::cout << std::endl << "EDGE CASE" << std::endl;
	gate_keeper.attack("Hodor");
	hodor.takeDamage(120);
	hodor.beRepaired(5);

	std::cout << std::endl << "COPY CONSTRUCTORS" << std::endl;
	ScavTrap	gate_keeper2 = ScavTrap(gate_keeper);
	ScavTrap	hodor2;

	hodor2 = hodor;
	gate_keeper2.beRepaired(0);
	hodor2.beRepaired(0);

	std::cout << std::endl << "DESTRUCTORS" << std::endl;
	return (0);
}
