#include "Span.hpp"

Span::Span(void) :
	_max_size(0),
	_size(0),
	_vect(0, 0) {
	std::cout << "Span default constructor called" << std::endl;
	return ;
}

Span::Span(unsigned int max_size) :
	_max_size(max_size),
	_size(0),
	_vect(max_size, 0) {
	std::cout << "Span parameterized constructor called" << std::endl;
	return ;
}

Span::Span(Span const & src) :
	_max_size(src._max_size),
	_size(src._size),
	_vect(src._vect.begin(), src._vect.end()) {
	std::cout << "Span copy constructor called" << std::endl;
	return ;
}

Span&	operator=(Span const & src) {
	_max_size = src._max_size;
	_size = src._max_size;
	// copy vector one by one?
	return (*this);
}

Span::~Span(void) {
	std::cout << "Span destructor called" << std::endl;
	// need to delete vector in some way? if yes I should allocate it first
	return ;
}

/* https://cplusplus.com/reference/vector/vector/ */