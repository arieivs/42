#ifndef ITER_HPP
# define ITER_HPP

/* normal function */
template<typename T>
void	iter(T* arr, int len, void(*f)(T&)) {
	int	i;

	for (i = 0; i < len; i++)
		f(arr[i]);
}

/* function with const parameter
 * use std::size_t instead of int for len to avoid ambiguity
 * between function calls
 */
template<typename T>
void	iter(T* arr, std::size_t len, void(*f)(T const &)) {
	std::size_t	i;

	for (i = 0; i < len; i++)
		f(arr[i]);
}

/* template function */
template<typename T, typename F>
void	iter(T* arr, std::size_t len, F f) {
	std::size_t	i;

	for (i = 0; i < len; i++)
		f(arr[i]);
}

#endif
