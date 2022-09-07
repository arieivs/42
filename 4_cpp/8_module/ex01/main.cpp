#include "Span.hpp"

int	main(void) {
	Span	span(4);
	Span	empty_span(4);
	int		range_span;

	try {
		span.addNumber(5);
		span.addNumber(7);
		span.addNumber(3);
		span.addNumber(1);
		span.addNumber(2);
	}
	catch (Span::SpanIsFullException& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		range_span = span.longestSpan();
		std::cout << "Longest span: " << range_span << std::endl;
		range_span = empty_span.longestSpan();
		std::cout << "Longest span: " << range_span << std::endl;
	}
	catch (Span::SpanNotFoundException& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		range_span = span.shortestSpan();
		std::cout << "Shortest span: " << range_span << std::endl;
		range_span = empty_span.shortestSpan();
		std::cout << "Shortest span: " << range_span << std::endl;
	}
	catch (Span::SpanNotFoundException& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
