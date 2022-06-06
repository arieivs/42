#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class Contact {
	public:
		char	*first_name;
		char	*last_name;
		char	*nickname;
		char	*phone_number;
		char	*darkest_secret;

		Contact(char *first_name, char *last_name, char*nickname,
			char *phone_number, char *darkest_secret);
		~Contact(void);

		int	compare(Contact *other);
};

#endif
