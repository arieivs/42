#include "phonebook.hpp"

Contact::Contact(char *first_name, char *last_name, char *nickname,
	char *phone_number, char *darkest_secret) :
	first_name(first_name),
	last_name(last_name),
	nickname(nickname),
	phone_number(phone_number),
	darkest_secret(darkest_secret)
{
	std::cout << "Contact created" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact destroyed" << std::endl;
	return ;
}

int	Contact::compare(Contact *other)
{
	if (strcmp(this->first_name, other->first_name) == 0 &&
		strcmp(this->last_name, other->last_name) == 0)
		return (1);
	return (0);
}

