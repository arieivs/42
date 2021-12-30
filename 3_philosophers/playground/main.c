#include <pthread.h>
#include <stdio.h>

// for now, as I'm lazy, I need to put the mutex in a struct to pass as arg
pthread_mutex_t	mutex;

void	*routine(void *nb)
{
	int	i;

	pthread_mutex_lock(&mutex);
	i = 0;
	while (i < 10000)
	{
		(*(int *)nb)++;
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return (nb); // non-void function, thus I must return something
}

int	main(void)
{
	int				arg;
	int				*res;
	int				i;
	pthread_t		threads[4];

	arg = 0;
	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < 4)
	{
		// give arguments with create (else NULL)
		if (pthread_create(&threads[i], NULL, &routine, (void *)&arg))
			return (1);
		printf("Thread %d started\n", i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		// receive return value with join (can be NULL)
		if (pthread_join(threads[i], (void **)&res))
			return (1);
		printf("Thread %d finished execution\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("Arg: %d, Res: %d\n", arg, *res);
	return (0);
}
