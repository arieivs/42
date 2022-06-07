#include "phonebook.hpp"

Contact::Contact(void)
{
	std::cout << "Contact created" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact destroyed" << std::endl;
	return ;
}

std::string	Contact::get_first_name(void) const
{
	return this->first_name;
}

std::string	Contact::get_last_name(void) const
{
	return this->last_name;
}

std::string	Contact::get_nickname(void) const
{
	return this->nickname;
}

std::string	Contact::get_phone_number(void) const
{
	return this->phone_number;
}

std::string	Contact::get_darkest_secret(void) const
{
	return this->darkest_secret;
}

void	Contact::set_contact_details(std::string first_name, std::string last_name,
			std::string nickname, std::string phone_number,
			std::string darkest_secret)
{
	if (first_name.empty() || last_name.empty() || nickname.empty() ||
		phone_number.empty() || darkest_secret.empty())
		return ;
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

bool	Contact::compare(Contact *other) const
{
	if (!this->first_name.empty() && !this->last_name.empty() &&
		this->first_name.compare(other->first_name) == 0 &&
		this->last_name.compare(other->last_name) == 0)
		return (true);
	return (false);
}

