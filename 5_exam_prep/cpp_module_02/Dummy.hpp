#ifndef DUMMY_HPP
# define DUMMY_HPP

# include <iostream>
# include "ATarget.hpp"

class Dummy : public ATarget {
	public:
		Dummy(void);
		Dummy(Dummy const & src);
		Dummy&	operator=(Dummy const & src);
		~Dummy(void);

		virtual ATarget*	clone(void) const;
};

#endif