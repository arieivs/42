#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Wrong parameters:"
				  << " please provide <filename> <string1> <string2>"
				  << std::endl;
		return (1);
	}

	std::string		filename = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::ifstream	in_file;
	std::ofstream	out_file;

	in_file.open(filename);
	if (in_file.is_open())
	{
		// Nops this did not work
		std::cerr << "File does not exit" << std::endl;
		return (1);
	}
	out_file.open(filename + ".replace");
	// do something
	in_file.close();
	out_file.close();
	return (0);
}