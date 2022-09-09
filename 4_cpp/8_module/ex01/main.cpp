#include "Span.hpp"
#define ARR_SIZE 100

int	main(void) {
	{
		std::cout << "SUBJECT" << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "EXCEPTIONS" << std::endl;
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
	}
	{
		std::cout << std::endl << "RANGE" << std::endl;
		int					arr[ARR_SIZE];
		int					i;
		std::vector<int>	vect;
		Span				span(ARR_SIZE + 1);
		Span				span2(ARR_SIZE + 1);
		int					range_span;
		int					range_span2;

		for (i = 0; i < ARR_SIZE; i++)
			arr[i] = i;
		vect = std::vector<int>(arr, arr + ARR_SIZE);
		try {
			span.addNumbers(arr, arr + ARR_SIZE);
			span2.addNumbers(vect.begin(), vect.end());
		}
		catch (Span::SpanIsFullException& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			range_span = span.longestSpan();
			range_span2 = span2.longestSpan();
			std::cout << "Longest span: " << range_span << ", " << range_span2 << std::endl;
			range_span = span.shortestSpan();
			range_span2 = span2.shortestSpan();
			std::cout << "Shortest span: " << range_span << ", " << range_span2 << std::endl;
		}
		catch (Span::SpanNotFoundException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
