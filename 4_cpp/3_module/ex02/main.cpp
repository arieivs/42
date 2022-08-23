#include "FragTrap.hpp"

int	main(void) {
	std::cout << "CONSTRUCTORS" << std::endl;
	FragTrap	social_butterfly = FragTrap("Social Butterfly");
	FragTrap	nice_guy = FragTrap("Nice Guy");

	std::cout << std::endl << "ATTACK AND HIGH FIVES" << std::endl;
	social_butterfly.attack("Nice Guy");
	nice_guy.takeDamage(social_butterfly.getAttackDamage());
	nice_guy.beRepaired(5);
	nice_guy.highFivesGuys();

	std::cout << std::endl << "DESTRUCTORS" << std::endl;
	return (0);
}
