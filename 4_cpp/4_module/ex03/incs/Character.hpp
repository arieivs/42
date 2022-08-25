#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# define INVENTORY_SPACE 4

class Character : public ICharacter {
	public:
		Character(void);
		Character(std::string name);
		Character(Character const & src);
		Character&	operator=(Character const & src);
		~Character();

		std::string const &	getName(void) const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
	
	private:
		std::string	_name;
		AMateria*	_inventory[INVENTORY_SPACE];
		int			_occupied_slots;
		// used_inventory? to delete after unequip?
};

#endif
