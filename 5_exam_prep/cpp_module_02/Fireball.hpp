#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include <iostream>
# include "ASpell.hpp"

class Fireball : public ASpell {
	public:
		Fireball(void);
		Fireball(Fireball const & src);
		Fireball&	operator=(Fireball const & src);
		~Fireball(void);

		virtual ASpell*	clone(void) const;
};

#endif