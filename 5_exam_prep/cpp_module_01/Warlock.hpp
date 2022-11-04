#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <vector>
# include "ASpell.hpp"
# include "ATarget.hpp"

/*
 * Coplien's form:
 * - constructor
 * - copy constructor
 * - operator= overload
 * - destructor
 *
 * However, our Warlock cannot be:
 * - instantiated without name and title => no default constructor
 * - instatiated by copy => private copy constructor (simply not having it,
 *   won't work!!)
 * - able to be copied => private opeartor= overload (simply not having it,
 *   won't work!!)
*/

class Warlock {
	public:
		Warlock(std::string name, std::string title);
		~Warlock(void);

		std::string const &	getName(void) const;
		std::string const &	getTitle(void) const;
		void				setTitle(std::string const & new_title);
		void				introduce() const;
		void				learnSpell(ASpell* spell);
		void				forgetSpell(std::string spell_name);
		void				launchSpell(std::string spell_name, ATarget& target);

	private:
		std::string				name;
		std::string				title;
		std::vector<ASpell*>	spells;

		Warlock(Warlock const & src);
		Warlock const &	operator=(Warlock const & src);
};

#endif