#ifndef A_SPELL_HPP
# define A_SPELL_HPP

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell {
	public:
		ASpell(void);
		ASpell(std::string name, std::string effects);
		ASpell(ASpell const & src);
		ASpell&	operator=(ASpell const & src);
		~ASpell(void);

		std::string	getName(void) const;
		std::string	getEffects(void) const;
		void		launch(ATarget const & target);

		ASpell*	clone(void) const = 0;

	protected:
		std::string	name;
		std::string	effects;
};

#endif