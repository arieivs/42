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

/*
std::string:npos -> https://cplusplus.com/reference/string/string/npos/
*/
void	sed(std::string *content, std::string s1, std::string s2)
{
	std::size_t	found = 0;
	std::size_t	len1;

	len1 = s1.length();
	if (len1 == 0)
		return ;
	while ((found = content->find(s1, found)) != std::string::npos)
	{
		content->erase(found, len1);
		content->insert(found, s2);
		found++;
	}
}

/*
Read File into String
"istreambuf_iterator is an input iterator that reads successive characters from the
std::basic_streambuf object. Thus we can utilize istreambuf_iterator with an ifstream stream and read 
the whole contents of the file into a std::string"
*/
int	main(int ac, char **av)
{
	std::ifstream	in_file;
	std::ofstream	out_file;
	std::string		content;

	if (ac != 4)
	{
		std::cerr << "Wrong parameters:"
				  << " please provide <filename> <string1> <string2>"
				  << std::endl;
		return (1);
	}
	if (open_or_error(av[1], &in_file, &out_file))
		return (1);
	content = std::string(std::istreambuf_iterator<char>(in_file), std::istreambuf_iterator<char>());
	sed(&content, av[2], av[3]);
	out_file << content;
	if (close_or_error(av[1], &in_file, &out_file))
		return (1);
	return (0);
}