#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	agenda;
	int	i;

	for (i = 0; i < 10; i++)
	{
		agenda.add_contact();
		agenda.search();
	}
	return (0);
}
