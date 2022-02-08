#include <sys/types.h> // for pid_t
#include <unistd.h> // for fork()
#include <semaphore.h>
#include <stdio.h>

void	talk(sem_t *semaphore, char *who)
{
	sem_wait(semaphore);
	printf("%s is talking\n", who);
	//sem_post(semaphore);
}

int	main(void)
{
	pid_t	pid;
	sem_t	*semaphore;

	sem_unlink("nb_microphones");
	semaphore = sem_open("nb_microphones", O_CREAT, 0755, 0);
	pid = fork();
	if (pid == 0)
	{
		// Child process
		talk(semaphore, "Child");
	}
	else
	{
		// Parent process
		talk(semaphore, "Parent");
	}
	sem_close(semaphore);
	return (0);
}
