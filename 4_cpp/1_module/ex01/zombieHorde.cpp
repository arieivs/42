#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zombies = new Zombie[N];
	int		i;

	for (i = 0; i < N; i++)
		zombies[i] = Zombie(name);
	return (zombies);
}

/*
Initializing an array of objects with parameterized constructors
1) using a dummy constructor
in Zombie.hpp/cpp file:
Zombie() {}

in this file:
Zombie	*zombies = new Zombie[N];
for (i = 0; i < N; i++)
	zombies[i] = Zombie(name);

Problem: the destructor is called when zombies[i] = Zombie(name) is called

2) using a double pointer
in this file:
Zombie	**zombies = new Zombie*[N];
for (i = 0; i < N; i++)
		zombies[i] = new Zombie(name);

Problem: doesn't work well if I neew to return *zombie

Learn more:
https://www.geeksforgeeks.org/how-to-initialize-array-of-objects-with-parameterized-constructors-in-c/
*/