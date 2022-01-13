#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

int	main(void)
{
	struct timeval	now;
	
	gettimeofday(&now, NULL);
	printf("now: %ld seconds, %d microseconds\n", now.tv_sec, now.tv_usec);
	usleep(1000);
	gettimeofday(&now, NULL);
	printf("now: %ld seconds, %d microseconds\n", now.tv_sec, now.tv_usec);
	usleep(1000);
	gettimeofday(&now, NULL);
	printf("now: %ld seconds, %d microseconds\n", now.tv_sec, now.tv_usec);
	return (0);
}
