#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies;
	int		i;
	int		n = 4;

	zombies = zombieHorde(n, "Brian");
	for (i = 0; i < n; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}