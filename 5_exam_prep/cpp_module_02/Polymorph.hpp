#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include <iostream>
# include "ASpell.hpp"

class Polymorph : public ASpell {
	public:
		Polymorph(void);
		Polymorph(Polymorph const & src);
		Polymorph&	operator=(Polymorph const & src);
		~Polymorph(void);

		virtual ASpell*	clone(void) const;
};

#endif