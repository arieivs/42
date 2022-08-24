#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
	public:
		Dog(void);
		Dog(Dog const & src);
		Dog&	operator=(Dog const & src);
		~Dog(void);

		virtual void		makeSound(void) const;
		virtual std::string	getIdea(int i) const;
		virtual void		setIdea(int i, std::string idea);
	
	private:
		Brain*	brain;
};

#endif
