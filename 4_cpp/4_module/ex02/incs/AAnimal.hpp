#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

# include <iostream>

class AAnimal {
	public:
		AAnimal(void);
		AAnimal(AAnimal const & src);
		AAnimal&	operator=(AAnimal const & src);
		virtual ~AAnimal(void);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;

	protected:
		std::string	type;
};

#endif
