#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# define INVENTORY_SPACE 4

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		MateriaSource&	operator=(MateriaSource const & src);
		~MateriaSource(void);
		
		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);

	private:
		AMateria*	_inventory[INVENTORY_SPACE];
		int			_occupied_slots;
};

#endif
