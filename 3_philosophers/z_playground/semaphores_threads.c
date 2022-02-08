#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h> // for rand()

#define THREADS_NR 10
#define BUFFER_SIZE 10

/* Very simplified version of the Producer Consumer Problem */

typedef struct s_args
{
	pthread_mutex_t	mutex_buffer;
	sem_t			*sem_empty;
	sem_t			*sem_full;
	int				*buffer;
	int				counter;
}				t_args;

void	*producer(void	*undef_args)
{
	t_args	*args;

	args = (t_args *)undef_args;
	printf("Waiting for storing produced item\n");
	sem_wait(args->sem_empty);
	args->buffer[args->counter] = rand() % 100;
	args->counter++;
	printf("Stored produced item\n");
	sem_post(args->sem_full);
	return (NULL);
}

void	*consumer(void *undef_args)
{
	t_args	*args;

	args = (t_args *)undef_args;
	printf("Waiting for having items to consume\n");
	sem_wait(args->sem_full);
	args->counter--;
	printf("Consumed %d\n", args->buffer[args->counter]);
	sem_post(args->sem_empty);
	return (NULL);
}

int	main(void)
{
	pthread_t	*threads;
	t_args		args;
	int			i;

	threads = (pthread_t *)malloc(sizeof(pthread_t) * THREADS_NR);
	pthread_mutex_init(&args.mutex_buffer, NULL);
	args.sem_full = sem_open("nb full places", O_CREAT, O_RDWR, 0);
	args.sem_empty = sem_open("nb empty places", O_CREAT, O_RDWR, BUFFER_SIZE);
	args.buffer = (int *)malloc(sizeof(int) * BUFFER_SIZE);
	args.counter = 0;
	i = 0;
	while (i < THREADS_NR)
	{
		if (i % 2 == 0)
		{
			if (pthread_create(&threads[i], NULL, &producer, (void *)&args))
				return (1);
		}
		else
		{
			if (pthread_create(&threads[i], NULL, &consumer, (void *)&args))
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
	pthread_mutex_destroy(&args.mutex_buffer);
	sem_close(args.sem_empty);
	sem_close(args.sem_full);
	free(args.buffer);
	free(threads);
	return (0);
}
