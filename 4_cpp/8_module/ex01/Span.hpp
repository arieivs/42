#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <limits>

class Span {
	public:
		Span(void);
		Span(unsigned int max_size);
		Span(Span const & src);
		Span&	operator=(Span const & src);
		~Span(void);

		void	addNumber(int n);
		void	addNumbers(int* begin, int* end);
		int		longestSpan(void) const;
		int		shortestSpan(void) const;

		class SpanIsFullException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class SpanNotFoundException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		unsigned int		_max_size;
		std::vector<int>	_vect;
};

#endif
