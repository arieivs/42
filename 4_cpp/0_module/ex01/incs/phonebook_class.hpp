#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add_contact(void);
		void	search(void);

	private:
		Contact	contacts[8];
		int		next_index;
		int		nb_contacts;

		/* auxiliary for add_contact */
		std::string	ask_user_for_input(std::string field);
		/* auxiliary for search */
		void		write_row_display_all(std::string content, bool is_last_row);
		void		display_all(void); 
		int			ask_user_for_index(void);

		//	displayAll, askUserIndex, displayOne
};

#endif
