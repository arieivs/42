#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal&	operator=(WrongAnimal const & src);
		~WrongAnimal(void);

		std::string	getType(void) const;
		void		makeSound(void) const;

	protected:
		std::string	type;
};

#endif
