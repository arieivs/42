#ifndef A_TARGET_HPP
# define A_TARGET_HPP

# include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
	public:
		ATarget(void);
		ATarget(std::string type);
		ATarget(ATarget const & src);
		ATarget&	operator=(ATarget const & src);
		virtual ~ATarget(void);

		std::string			getType(void) const;
		void				getHitBySpell(ASpell const & spell) const;

		virtual ATarget*	clone(void) const = 0;

	protected:
		std::string	type;
};

#endif