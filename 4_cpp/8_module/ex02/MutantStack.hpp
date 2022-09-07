#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <iterator>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		class iterator :
			public std::iterator<std::bidirectional_iterator_tag, MutantStack> {

		};

		iterator	begin(void);
		iterator	end(void);
};

#endif