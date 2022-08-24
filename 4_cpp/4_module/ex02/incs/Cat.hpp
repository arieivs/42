#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
	public:
		Cat(void);
		Cat(Cat const & src);
		Cat&	operator=(Cat const & src);
		~Cat(void);

		virtual void			makeSound(void) const;
		virtual std::string     getIdea(int i) const;
		virtual void            setIdea(int i, std::string idea);

	private:
		Brain*	brain;
};

#endif
