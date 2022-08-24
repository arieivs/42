#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice(void);
		Ice(Ice const & src);
		Ice&	operator=(Ice const & src);
		~Ice(void);

		virtual Ice*		clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif
