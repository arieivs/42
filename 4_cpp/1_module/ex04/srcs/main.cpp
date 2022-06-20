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
int	open_or_error(std::string filename, std::ifstream *in_file, std::ofstream *out_file)
{
	in_file->open(filename);
	if (in_file->fail())
	{
		std::cerr << "Could not open the file " << filename << std::endl;
		return (1);
	}
	out_file->open(filename + ".replace");
	if (out_file->fail())
	{
		std::cerr << "Could not create the replace output file" << std::endl;
		return (1);
	}
	return (0);
}

int	close_or_error(std::string filename, std::ifstream *in_file, std::ofstream *out_file)
{
	in_file->close();
	if (in_file->fail())
	{
		std::cerr << "Could not close the file " << filename << std::endl;
		return (1);
	}
	out_file->close();
	if (out_file->fail())
	{
		std::cerr << "Could not close the replace output file" << std::endl;
		return (1);
	}
	return (0);
}

// later on it should return something...
void	sed(std::string content, std::string s1, std::string s2)
{
	std::cout << content;
	std::cout << s1 << " " << s2 << std::endl;
}

/*
Read File into String
"istreambuf_iterator is an input iterator that reads successive characters from the
std::basic_streambuf object. Thus we can utilize istreambuf_iterator with an ifstream stream and read 
the whole contents of the file into a std::string"
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

	std::ifstream	in_file;
	std::ofstream	out_file;
	std::string		content;

	if (open_or_error(av[1], &in_file, &out_file))
		return (1);
	content = std::string(std::istreambuf_iterator<char>(in_file), std::istreambuf_iterator<char>());
	sed(content, av[2], av[3]);
	out_file << content; // later on the new content
	if (close_or_error(av[1], &in_file, &out_file))
		return (1);
	return (0);
}