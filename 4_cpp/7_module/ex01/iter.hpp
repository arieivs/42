#ifndef ITER_HPP
# define ITER_HPP

/* template function - generic case */
template<typename T, typename F>
void	iter(T* arr, std::size_t len, F f) {
	std::size_t	i;

	for (i = 0; i < len; i++)
		f(arr[i]);
}

/* function with parameter of type T& - specific case*/
/* int vs size_t -> changing the type is a way to avoid ambiguity */
template<typename T>
void	iter(T* arr, int len, void(*f)(T &)) {
	int	i;

	for (i = 0; i < len; i++)
		f(arr[i]);
}

/* function with parameter of type T const & - specific case*/
template<typename T>
void	iter(T* arr, std::size_t len, void(*f)(T const &)) {
	std::size_t	i;

	for (i = 0; i < len; i++)
		f(arr[i]);
}

#endif
