#include "Span.hpp"

Span::Span(void) :
	_max_size(10) {
	std::cout << "Span default constructor called" << std::endl;
	_vect.reserve(10);
	return ;
}

Span::Span(unsigned int max_size) :
	_max_size(max_size) {
	std::cout << "Span parameterized constructor called" << std::endl;
	try {
		_vect.reserve(max_size);
	}
	catch (std::length_error& e) {
		size_t	sys_max_size = _vect.max_size();
		_vect.reserve(sys_max_size);
		std::cout << e.what() << " - span created with size "
				  << sys_max_size << std::endl;
	}
	return ;
}

Span::Span(Span const & src) :
	_max_size(src._max_size),
	_vect(src._vect) {
	std::cout << "Span copy constructor called" << std::endl;
	return ;
}

Span&	Span::operator=(Span const & src) {
	_max_size = src._max_size;
	_vect = src._vect;
	return (*this);
}

Span::~Span(void) {
	std::cout << "Span destructor called" << std::endl;
	return ;
}

void	Span::addNumber(int n) {
	if (_vect.size() == _max_size) {
		throw Span::SpanIsFullException();
		return ;
	}
	_vect.push_back(n);
}

/* a pseudo range of iterators, more useful if you ask me */
void	Span::addNumbers(int* begin, int* end) {
	if ((_vect.size() + (end - begin)) >= _max_size) {
		throw Span::SpanIsFullException();
		return ;
	}
	_vect.insert(_vect.end(), begin, end);
}

/* an actual range of iterators */
void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if ((_vect.size() + (end - begin)) >= _max_size) {
		throw Span::SpanIsFullException();
		return ;
	}
	_vect.insert(_vect.end(), begin, end);
}

/* std::vector<const int>::iterator = std::vector<int>::const_iterator */
int	Span::longestSpan(void) const {
	int									longest_span;
	std::vector<int>::const_iterator	min;
	std::vector<int>::const_iterator	max;

	if (_vect.size() == 0) {
		throw Span::SpanNotFoundException();
		return (-1);
	}
	min = std::min_element(_vect.begin(), _vect.end());
	max = std::max_element(_vect.begin(), _vect.end());
	longest_span = *max - *min;
	return (longest_span);
}

int	Span::shortestSpan(void) const {
	int							shortest_span = std::numeric_limits<int>::max();
	std::vector<int>			ordered_vect(_vect);
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	ite = ordered_vect.end();

	if (_vect.size() == 0) {
		throw Span::SpanNotFoundException();
		return (-1);
	}
	std::sort(ordered_vect.begin(), ite);
	for (it = ordered_vect.begin(); it + 1 != ite; it++) {
		if (*(it + 1) - *it < shortest_span)
			shortest_span = *(it + 1) - *it;
	}
	return (shortest_span);
}

void	Span::printNumbers(void) const {
	std::vector<int>::const_iterator	ite = _vect.end();
	std::vector<int>::const_iterator	it;

	for (it = _vect.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

const char*	Span::SpanIsFullException::what() const throw() {
	return "Span has no space left";
}

const char*	Span::SpanNotFoundException::what() const throw() {
	return "Span is empty";
}
