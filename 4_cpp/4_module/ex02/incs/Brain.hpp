#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# define NR_IDEAS 100

class Brain {
	public:
		Brain(void);
		Brain(Brain const & src);
		Brain&	operator=(Brain const & src);
		~Brain(void);

		std::string*	getIdeas(void);
		std::string		getIdea(int i) const;
		void			setIdea(int i, std::string idea);
	
	private:
		std::string	ideas[NR_IDEAS];
};

#endif
