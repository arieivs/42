#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(void) {
	int					arr[] = {2, 4, 6, 8};
	size_t				arr_len = (sizeof(arr) / sizeof(int));
	std::vector<int>	vect(arr, arr + arr_len);
	int					found;

	try {
		found = easyfind(vect, 4);
		std::cout << "Found number " << found << std::endl;
	}
	catch (IntegerNotFound& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		found = easyfind(vect, 5);
		std::cout << "Found number " << found << std::endl;
	}
	catch (IntegerNotFound& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}