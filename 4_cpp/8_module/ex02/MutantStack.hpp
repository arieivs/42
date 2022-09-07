#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <iterator>
// these classes also need to be orthodox?
// https://en.cppreference.com/w/cpp/iterator/iterator
// https://cplusplus.com/reference/iterator/iterator/
template<typename T>
class MutantStack : public std::stack<T> {
	public:
		class iterator : public std::iterator<std::bidirectional_iterator_tag,
											  std::stack<T>,
											  std::stack<T>,
											  std::stack<T>*,
											  std::stack<T>& > {
			private:
				std::stack<T>	_stack;
			public:
				// entao... preciso de qq coisa... mas o q? uma stack?
				// long num = FROM; (private)
				// why explicit?
				explicit iterator(std::stack<T> stack) : _stack(stack) {} // constructor
				iterator(iterator const & src) : _stack(src._stack) {}
				iterator&	operator++() {
					++_stack; // not going to work
					return (*this);
				}
				iterator	operator++(std::stack<T>) {
					iterator previous = *this;
					++(*this); // probably won't work either
					return previous;
				}
				// missing --
				bool		operator==(iterator other) const {
					return _stack == other._stack;
				}
				bool		operator!=(iterator other) const {
					return _stack != other._stack;
				}
				std::stack<T>&	operator*() const {
					return _stack;
				}

				/*iterator&	operator++() {num = Treturn _stack.top();
				// int* p; (private)
				MyIterator(int* x) :p(x) {} // constructor
				MyIterator(const MyIterator& mit) : p(mit.p) {} // copy constructor
				MyIterator& operator++() {++p;return *this;}
				MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
				bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
				bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
				int& operator*() {return *p;}*/
		};

		iterator	begin(void) {
			return _stack.top();
		}
		iterator	end(void) {
			return _stack.top();
		} // ah pois... como? temporario. acho que preciso de duas stacks...
};

#endif