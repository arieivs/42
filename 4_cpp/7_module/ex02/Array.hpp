#ifndef ARRAY_HPP
# define ARRAY_HPP

/* new[]
 * allocates memory for the array, and if successful
 * allocates memory and constructs each object from the array */

template<typename T>
class Array {
	public:
		Array(void) : _size(0), _array(new T()) {
			return ;
		}
		Array(unsigned int n) : _size(n), _array(new T[n]) {
			return ;
		}
		Array(Array const & src) :
			_size(src._size),
			_array(new T[src._size]) {
			unsigned int	i;

			for (i = 0; i < _size; i++)
				_array[i] = T(src._array[i]); 
			return ;
		}
		Array&	operator=(Array const & src) {
			unsigned int	i;

			_size = src.size;
			_array = new T[src.size];
			for (i = 0; i < _size; i++)
				_array[i] = T(src._array[i]); 
			return (*this);
		}
		~Array(void) {
			delete [] _array;
			return ;
		}

		unsigned int	size(void) const {
			return _size;
		}
		
		T&	operator[](unsigned int i) {
			if (i >= _size) {
				throw IndexOutBounds();
				return _array[0];
			}
			return _array[i];
		}

		class IndexOutBounds : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Index out of boundaries";
				}
		};

	private:
		unsigned int	_size;
		T*				_array;
};

#endif
