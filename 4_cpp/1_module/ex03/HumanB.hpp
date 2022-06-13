#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB {
	public:
		std::string	name;
		Weapon*		weapon;

		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon& weapon);
		void	attack(void);
};

#endif