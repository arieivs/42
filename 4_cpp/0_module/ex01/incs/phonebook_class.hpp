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

		/* auxiliary for add_contact */
		std::string	ask_user_for_input(std::string field);
		/* auxiliary for search */
		void		write_row_display_all(std::string content, bool is_last_row);
		void		display_all(void); 

		//	displayAll, askUserIndex, displayOne
};

#endif
