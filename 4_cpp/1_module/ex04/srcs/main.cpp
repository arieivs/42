#include <iostream>
#include <fstream>

/*
Checking if open failed
(file doesn't exist, lack of permissions, etc...)
in_file.open(filename);

if (in_file == NULL)
if ((in_file.rdstate() & std::ifstream::failbit) != 0)
if (in_file.fail())

https://cplusplus.com/reference/ios/ios_base/iostate/
*/
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
	if (in_file.fail())
	{
		std::cerr << "Could not open the file " << filename << std::endl;
		return (1);
	}
	out_file.open(filename + ".replace");
	if (out_file.fail())
	{
		std::cerr << "Could not create the replace output file" << std::endl;
		return (1);
	}
	// TODO the actual sed programme
	in_file.close();
	if (in_file.fail())
	{
		std::cerr << "Could not close the file " << filename << std::endl;
		return (1);
	}
	out_file.close();
	if (out_file.fail())
	{
		std::cerr << "Could not close the replace output file" << std::endl;
		return (1);
	}
	return (0);
}