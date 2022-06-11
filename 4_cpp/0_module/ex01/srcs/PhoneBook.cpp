#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->next_index = 0;
	this->nb_contacts = 0;
	DEBUG(std::cout << "PhoneBook created" << std::endl;)
	return ;
}

PhoneBook::~PhoneBook(void)
{
	DEBUG(std::cout << "PhoneBook destroyed" << std::endl;)
	return ;
}

std::string	PhoneBook::ask_user_for_input(std::string field) const
{
	std::string	new_value;

	std::cout << "What's the new contact's " << field << "?" << std::endl;
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

	std::cout << "🙋‍♀️ Adding a new contact! 🙋‍♂️" << std::endl;
	new_first_name = PhoneBook::ask_user_for_input("first name");
	new_last_name = PhoneBook::ask_user_for_input("last name");
	new_nickname = PhoneBook::ask_user_for_input("nickname");
	new_phone_number = PhoneBook::ask_user_for_input("phone number");
	new_darkest_secret = PhoneBook::ask_user_for_input("darkest secret");
	this->contacts[this->next_index].set_contact_details(new_first_name,
		new_last_name, new_nickname, new_phone_number, new_darkest_secret);
	this->next_index = (this->next_index + 1) % 8;
	if (this->nb_contacts < 8)
		this->nb_contacts++;
}

void	PhoneBook::write_row_display_all(std::string content,
			bool is_last_row) const
{
	if (content.length() > 10)
	{
		std::cout << std::setw(9);
		std::cout << content.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << content;
	}
	is_last_row ? std::cout << std::endl : std::cout << "|";
}

void	PhoneBook::display_all(void) const
{
	int	i;

	write_row_display_all("INDEX", false);
	write_row_display_all("FIRST NAME", false);
	write_row_display_all("LAST NAME", false);
	write_row_display_all("NICKNAME", true);
	for (i = 0; i < 8; i++)
	{
		if (this->contacts[i].get_first_name().empty())
			break ;
		std::cout << std::setw(10) << i + 1 << "|";
		write_row_display_all(this->contacts[i].get_first_name(), false);
		write_row_display_all(this->contacts[i].get_last_name(), false);
		write_row_display_all(this->contacts[i].get_nickname(), true);
	}
}

int		PhoneBook::ask_user_for_index(void) const
{
	int		index;

	while (true)
	{
		std::cout << "Which contact do you wish to see? Write its index: ";
		std::cin >> index;
		std::cout << std::endl;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(); /* Clear cin so that it doesn't go crazy */
			std::cout << "Please give a number" << std::endl;
			continue ;
		}
		if (index >= 1 && index <= this->nb_contacts)
			break ;
		std::cout << "Index out of range, please give a number beween 1 and ";
		std::cout << this->nb_contacts << std::endl;
	}
	return (index - 1);
}

void	PhoneBook::display_one_contact(int i) const
{
	std::cout << this->contacts[i].get_first_name() << std::endl;
	std::cout << this->contacts[i].get_last_name() << std::endl;
	std::cout << this->contacts[i].get_nickname() << std::endl;
	std::cout << this->contacts[i].get_phone_number() << std::endl;
	std::cout << this->contacts[i].get_darkest_secret() << std::endl;
}

void	PhoneBook::search(void) const
{
	int	index;

	std::cout << "🔍 Searching... 👀" << std::endl;
	if (this->nb_contacts <= 0)
	{
		std::cout << "Your phonebook is empty! Add a contact first" << std::endl;
		return ;
	}
	PhoneBook::display_all();
	index = PhoneBook::ask_user_for_index();
	PhoneBook::display_one_contact(index);
}

