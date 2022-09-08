#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <iterator>
// these classes also need to be orthodox?
// https://en.cppreference.com/w/cpp/iterator/iterator
// https://cplusplus.com/reference/iterator/iterator/
// https://www.learncpp.com/cpp-tutorial/stl-iterators-overview/
template<typename T>
class MutantStack : public std::stack<T> {
	public:
		// needs to be orthodox right?

		class iterator : public std::iterator<std::bidirectional_iterator_tag,
											  MutantStack<T>,
											  MutantStack<T>,
											  MutantStack<T>*,
											  MutantStack<T>& > {
			private:
				std::stack<T>	_stack;
				std::stack<T>	_backwards_stack;
			public:
				iterator(void) : _stack(), _backwards_stack() {}
				iterator(MutantStack<T> mstack) : _stack(mstack), _backwards_stack() {}
				iterator(iterator const & src) : _stack(src._stack),
												 _backwards_stack(src._backwards_stack) {}
				iterator&	operator=(iterator const & src) {
					_stack = src._stack;
					_backwards_stack = src._backwards_stack;
					return (*this);
				}
				~iterator(void) {}

				iterator&	operator++() {
					T	element = _stack.top();

					_stack.pop();
					_backwards_stack.push(element);
					return (*this);
				}
				iterator	operator++(int) {
					iterator	previous = *this;
					T	element = _stack.top();

					_stack.pop();
					_backwards_stack.push(element);
					return (previous);
				}
				iterator&	operator--() {
					T	element = _backwards_stack.top();

					_backwards_stack.pop();
					_stack.push(element);
					return (*this);
				}
				iterator	operator--(int) {
					iterator	previous = *this;
					T	element = _backwards_stack.top();

					_backwards_stack.pop();
					_stack.push(element);
					return (previous);
				}
				bool		operator==(iterator other) const {
					return (_stack == other._stack && _backwards_stack == other._backwards_stack);
				}
				bool		operator!=(iterator other) const {
					return (_stack != other._stack || _backwards_stack != other._backwards_stack);
				}
				T const &	operator*() const {
					return _stack.top();
				}
		};

		iterator	begin(void) {
			return iterator(*this);
		}
		iterator	end(void) {
			return iterator(*(this + this->size())); // seg fault... but it should be end, no?
		}
};

#endif