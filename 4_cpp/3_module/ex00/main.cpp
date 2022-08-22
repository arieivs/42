#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	baloney = ClapTrap("Baloney");
	ClapTrap	bogos = ClapTrap("Bogos");

	/* Ideal scenario */
	baloney.attack("Bogos");
	bogos.takeDamage(baloney.getAttackDamage());
	bogos.beRepaired(5);

	/* Edge case scenario */
	bogos.attack("Baloney");
	baloney.takeDamage(12);
	baloney.beRepaired(5);

	/* Copying */
	ClapTrap	bogos2 = ClapTrap(bogos);
	ClapTrap	baloney2;

	baloney2 = baloney;
	bogos2.beRepaired(0);
	baloney2.beRepaired(0);

	return (0);
}
