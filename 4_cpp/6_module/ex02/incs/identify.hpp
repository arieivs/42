#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include <time.h>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# ifdef DEBUG_MODE
#  define DEBUG(x) x
# else
#  define DEBUG(x)
# endif

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
