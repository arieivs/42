#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA {
	public:
		std::string	name;
		Weapon&		weapon;

		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		void	attack(void);
};

#endif