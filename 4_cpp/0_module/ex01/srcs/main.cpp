#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	agenda;
	std::string	user_input;

	std::cout << "🤗 WELCOME TO YOUR DIGITAL PHONEBOOK! ☎️" << std::endl;
	while (true)
	{
		std::cout << "What do you wish to do? ADD, SEARCH or EXIT?" << std::endl;
		std::cin >> user_input;
		std::cout << std::endl;
		if (user_input.compare("ADD") == 0)
			agenda.add_contact();
		else if (user_input.compare("SEARCH") == 0)
			agenda.search();
		else if (user_input.compare("EXIT") == 0)
		{
			std::cout << "Goodbye! 👋" << std::endl;
			break ;
		}
		else
			std::cout << "❌ Not a valid input!";
		std::cout << std::endl;
	}
	return (0);
}
