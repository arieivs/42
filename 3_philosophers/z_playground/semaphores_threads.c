#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define THREADS_NR 2
#define BUFFER_SIZE 10

/* Very simplified version of the Producer Consumer Problem */

typedef struct s_args
{
	pthread_mutex_t	mutexBuffer;
	sem_t			semEmpty;
	sem_t			semFull;
	int				buffer[BUFFER_SIZE];
}				t_args;

void	*producer(void	*args)
{
	sem_wait
}

void	*consumer(void *args)
{
}

int	main(void)
{
	pthread_t	threads[THREADS_NR];
	t_args		args;
	int			i;

	pthread_mutex_init(&args.mutexBuffer, NULL);
	sem_init(&args.semEmpty, 0, BUFFER_SIZE);
	sem_init(&args.semFull, 0, 0);
	i = 0;
	while (i < THREADS_NR)
	{
		if (i % 2 == 0)
		{
			if (pthread_create(&threads[i], NULL, &producer, (void *)args))
				return (1);
		}
		else
		{
			if (pthread_create(&threads[i], NULL, &consumer, (void *)args))
				return (1);
		}
		i++;
	}
	i = 0;
	while (i < THREADS_NR)
	{
		if (pthread_join(threads[i], NULL))
			return (1);
		i++;
	}
	// destroy mutex and semaphores
	return (0);
}
