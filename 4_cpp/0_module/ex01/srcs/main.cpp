#include "phonebook.hpp"

int	main(void)
{
	Contact	neighbour("Mario", "Carneiro", "Neco", "000", "cats");
	Contact	neighbour2("Mario", "Carneiro", "Branco", "001", "cats");
	Contact	neighbour3("Mario", "Costa", "Neco", "000", "cats");

	printf("New contact: %s %s, %s, %s, %s\n", neighbour.first_name, neighbour.last_name, neighbour.nickname, neighbour.phone_number, neighbour.darkest_secret);
	if (neighbour.compare(&neighbour2))
		printf("1 and 2 are the same!\n");
	if (neighbour.compare(&neighbour3))
		printf("1 and 3 are the same!\n");
	return (0);
}
