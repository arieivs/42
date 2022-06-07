#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add_contact(void);
		// search function -> use c++ iomanips(WTF?)
		void		display_all(void); // TODO pass this to private

	private:
		Contact	contacts[8];
		int		next_index;

		std::string	ask_user_for_input(std::string field);
		// aux functions for search:
		//	displayAll, askUserIndex, displayOne
};

#endif
