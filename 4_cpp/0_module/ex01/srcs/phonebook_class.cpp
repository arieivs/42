#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	this->next_index = 0;
	std::cout << "PhoneBook created" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destroyed" << std::endl;
	return ;
}

std::string	PhoneBook::ask_user_for_input(std::string field)
{
	std::string	new_value;

	std::cout << "What's the new contact's " << field << " ?" << std::endl;
	/* using std::getline(std::cin, new_value) instead of std::cin >> new_value
	so that I can evaluate what the user wrote after each line
	default behaviour of std::cin is to wait until something is written */
	std::getline(std::cin, new_value);
	while (new_value.empty())
	{
		std::cout << "Value can't be empty! Try again:" << std::endl;
		std::getline(std::cin, new_value);
	}
	return new_value;
}

void	PhoneBook::add_contact(void)
{
	std::string	new_first_name;
	std::string	new_last_name;
	std::string	new_nickname;
	std::string	new_phone_number;
	std::string	new_darkest_secret;

	new_first_name = PhoneBook::ask_user_for_input("first name");
	new_last_name = PhoneBook::ask_user_for_input("last name");
	new_nickname = PhoneBook::ask_user_for_input("nickname");
	new_phone_number = PhoneBook::ask_user_for_input("phone number");
	new_darkest_secret = PhoneBook::ask_user_for_input("darkest secret");
	this->contacts[this->next_index].set_contact_details(new_first_name,
		new_last_name, new_nickname, new_phone_number, new_darkest_secret);
	this->next_index = (this->next_index + 1) % 8;
}

void	PhoneBook::display_all(void)
{
	int	i;

	for (i = 0; i < 8; i++)
	{
		if (this->contacts[i].get_first_name().empty())
			break ;
		std::cout << this->contacts[i].get_first_name() << "|";
		std::cout << this->contacts[i].get_last_name() << "|";
		std::cout << this->contacts[i].get_nickname() << "|";
		std::cout << this->contacts[i].get_phone_number() << "|";
		std::cout << this->contacts[i].get_darkest_secret() << std::endl;
	}
	// TODO 10 characters wide columns
}
