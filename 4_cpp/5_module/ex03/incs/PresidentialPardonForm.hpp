#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat;

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm&	operator=(PresidentialPardonForm const & src);
		~PresidentialPardonForm(void);

		virtual bool	execute(Bureaucrat const & executor) const;
	
	private:
		std::string	_target;

		void		grantPresidentialPardon(void) const;
};

#endif
