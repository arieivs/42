#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {
	public:
		Span(void);
		Span(unsigned int max_size);
		Span(Span const & src);
		Span&	operator=(Span const & src);
		~Span(void);

		addNumber(int n);
		shortestSpan(void) const;
		longestSpan(void) const;

	private:
		unsigned int	_max_size;
		unsigned int	_size;
		std::vector<in> _vect;
};

#endif