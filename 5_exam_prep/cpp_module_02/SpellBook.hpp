# ifndef SPELL_BOOK_HPP
# define SPELL_BOOK_HPP

# include <vector>
# include "ASpell.hpp"

class SpellBook {
	public:
		SpellBook(void);
		~SpellBook(void);
	
		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string const & spell_name);
		ASpell*	createSpell(std::string const & spell_name);

	private:
		std::vector<ASpell*>	spells;

		SpellBook(SpellBook const & src);
		SpellBook&	operator=(SpellBook const & src);
};

#endif