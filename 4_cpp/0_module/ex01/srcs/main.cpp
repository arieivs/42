#include "phonebook.hpp"

int	main(void)
{
	Contact	neighbour;
	
	neighbour.set_contact_details("Mário", "Carneiro", "vizinho", "000", "Neco");
	std::cout << neighbour.get_first_name() << neighbour.get_last_name();
	std::cout << neighbour.get_nickname() << neighbour.get_phone_number();
	std::cout << neighbour.get_darkest_secret() << std::endl;
	return (0);
}
