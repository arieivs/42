#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	{
		std::cout << "REGULAR PROCEDURES" << std::endl;
		Form		form_1a = Form("Form 1A", 10, 100);
		Form		form_1a_2 = Form(form_1a);
		Form		form_1a_3;
		Bureaucrat	john = Bureaucrat("John", 5);

		form_1a_3 = form_1a;
		std::cout << std::endl << form_1a << std::endl << form_1a_2
				  << std::endl << form_1a_3 << std::endl << std::endl;

		john.signForm(&form_1a);
		std::cout << form_1a << std::endl << std::endl;
	}
	{
		std::cout << std::endl << "IRREGULAR PROCEDURES" << std::endl;
		Form		form_2a = Form("Form 2A", -2, 160);
		Bureaucrat	simon = Bureaucrat("Simon", 5);
		
		std::cout << std::endl << form_2a << std::endl;

		simon.signForm(&form_2a);
		std::cout << form_2a << std::endl << std::endl;
	}
	return (0);
}
