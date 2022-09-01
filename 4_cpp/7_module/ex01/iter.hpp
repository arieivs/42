#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T* arr, int len, void(*f)(T&)) {
	int	i;

	for (i = 0; i < len; i++)
		f(arr[i]);
}

#endif
