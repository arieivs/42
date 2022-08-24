#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(WrongCat const & src);
		WrongCat&	operator=(WrongCat const & src);
		~WrongCat(void);

		void	makeSound(void) const;
};

#endif
