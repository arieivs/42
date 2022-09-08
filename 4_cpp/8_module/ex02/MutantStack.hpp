#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <iterator>

/* Useful resources:
 * https://en.cppreference.com/w/cpp/iterator/iterator
 * https://cplusplus.com/reference/iterator/iterator/
 * https://www.learncpp.com/cpp-tutorial/stl-iterators-overview/
 */
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
				iterator(MutantStack<T> mstack, bool reverse) : _stack(mstack), _backwards_stack() {
					if (reverse) {
						while (!_stack.empty()) {
							_backwards_stack.push(_stack.top());
							_stack.pop();
						}
					}
				}
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

					if (!_stack.empty()) {
						_stack.pop();
						_backwards_stack.push(element);
					}
					return (*this);
				}
				iterator	operator++(int) {
					iterator	previous = *this;
					T	element = _stack.top();

					if (!_stack.empty()) {
						_stack.pop();
						_backwards_stack.push(element);
					}
					return (previous);
				}
				iterator&	operator--() {
					T	element = _backwards_stack.top();

					if (!_backwards_stack.empty()) {
						_backwards_stack.pop();
						_stack.push(element);
					}
					return (*this);
				}
				iterator	operator--(int) {
					iterator	previous = *this;
					T	element = _backwards_stack.top();

					if (!_backwards_stack.empty()) {
						_backwards_stack.pop();
						_stack.push(element);
					}
					return (previous);
				}
				bool		operator==(iterator other) const {
					return (_stack == other._stack && _backwards_stack == other._backwards_stack);
				}
				bool		operator!=(iterator other) const {
					return (_stack != other._stack || _backwards_stack != other._backwards_stack);
				}
				/* I thought about protecting this. A lot.
				 * Yet I didn't find a solution effective for an empty stack.
				 * Additionally if you call top() on an std::stack you get a segmentation fault.
				 * on std::list::begin() "If the container is empty, the returned iterator value shall not be dereferenced."
				 * on std::list::front() "Calling this function on an empty container causes undefined behavior."
				 */
				T const &	operator*() const {
					return _stack.top();
				}
		};

		iterator	begin(void) {
			return iterator(*this);
		}
		iterator	end(void) {
			return iterator(*this, true);
		}
};

#endif