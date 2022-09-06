#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

class IntegerNotFound : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Integer not found in given container";
		}
};

/* T is a container of ints */
template<typename T>
int easyfind(T container, int n) {
	typename T::iterator	it;
	typename T::iterator	it_end = container.end();

	it = std::find(container.begin(), it_end, n);
	if (it == it_end) {
		throw IntegerNotFound();
		return (-1);
	}
	return (*it);
}

#endif