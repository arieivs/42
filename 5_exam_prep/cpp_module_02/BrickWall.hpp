#ifndef BRICK_WALL_HPP
# define BRICK_WALL_HPP

# include <iostream>
# include "ATarget.hpp"

class BrickWall : public ATarget {
	public:
		BrickWall(void);
		BrickWall(BrickWall const & src);
		BrickWall&	operator=(BrickWall const & src);
		~BrickWall(void);

		virtual ATarget*	clone(void) const;
};

#endif