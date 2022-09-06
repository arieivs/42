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
		_vect.reserve(sys_max_size); // should I?
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
	//TODO
	return (0);
}

const char*	Span::SpanIsFullException::what() const throw() {
	return "Span has no space left";
}

const char*	Span::SpanNotFoundException::what() const throw() {
	return "Span is empty";
}

/* https://cplusplus.com/reference/vector/vector/ */
