#include "Weapon.hpp"
#include "HumanA.hpp"

int	main(void)
{
	Weapon	sword = Weapon("sword");
	Weapon	axe = Weapon("axe");
	HumanA	alice = HumanA("Alice", axe);

	std::cout << sword.getType() << std::endl;
	std::cout << axe.getType() << std::endl;
	sword.setType("dagger");
	std::cout << sword.getType() << std::endl;
	alice.attack();
	return (0);
}