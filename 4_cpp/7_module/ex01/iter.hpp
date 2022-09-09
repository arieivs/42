#ifndef ITER_HPP
# define ITER_HPP

/* template function - generic case */
template<typename T, typename F>
void	iter(T* arr, std::size_t len, F f) {
	std::size_t	i;

	for (i = 0; i < len; i++)
		f(arr[i]);
}

/* function with const parameter */
template<typename T>
void	iter(T* arr, std::size_t len, void(*f)(T const &)) {
	std::size_t	i;

	for (i = 0; i < len; i++)
		f(arr[i]);
}

#endif
