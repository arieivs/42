#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	{
		Weapon	kniffe = Weapon("samurai sword");
		HumanA	alice("Alice", kniffe);

		alice.attack();
		kniffe.setType("sneaky dagger");
		alice.attack();
	}
	{
		Weapon	kniffe = Weapon("samurai sword");
		HumanB	bob("Bob");

		bob.setWeapon(kniffe);
		bob.attack();
		kniffe.setType("sneaky dagger");
		bob.attack();
	}
	return (0);
}