#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <iostream>

class AMateria {
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		AMateria&	operator=(AMateria const & src);
		virtual	~AMateria(void);

		std::string const &	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);

	protected:
		std::string	type;
};

#endif
