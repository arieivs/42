#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "basic_phonebook.hpp"
# include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add_contact(void);
		void	search(void) const;

	private:
		Contact	contacts[8];
		int		next_index;
		int		nb_contacts;

		/* auxiliary for add_contact */
		std::string	ask_user_for_input(std::string field) const;
		/* auxiliary for search */
		void		write_row_display_all(std::string content,
						bool is_last_row) const;
		void		display_all(void) const;
		int			ask_user_for_index(void) const;
		void		display_one_contact(int index) const;
};

#endif
