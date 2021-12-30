#include "philosophers.h"

int	main(void)
{
	int	n = 3;
	pthread_t		*philosophers;
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_init(&forks[i++], NULL);
		printf("fork %d created\n", i);
	}
	i = 0;
	while (i < n)
	{
		if (i == 0)
			data_philosopher_init(i + 1, &forks[n - 1], &forks[0])
		else
			data_philosopher_init(i + 1, &forks[i - 1], &forks[i])
		// create thread with struct
		i++
	}

