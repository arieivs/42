#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <iostream>
# include "ASpell.hpp"

class Fwoosh : public ASpell {
	public:
		Fwoosh(void);
		Fwoosh(Fwoosh const & src);
		Fwoosh&	operator=(Fwoosh const & src);
		~Fwoosh(void);

		ASpell*	clone(void) const;
};

#endif