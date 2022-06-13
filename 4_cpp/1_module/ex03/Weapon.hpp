#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string const &	getType(void) const;
		void	setType(std::string newType);
	private:
		std::string	_type;
};

#endif