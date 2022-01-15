#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

int	get_timestamp(struct timeval start)
{
	struct timeval	now;
	long long		now_ms;
	long long		start_ms;

	gettimeofday(&now, NULL);
	now_ms = (long long)(now.tv_sec * 1000) + now.tv_usec / 1000;
	start_ms = (long long)(start.tv_sec * 1000) + start.tv_usec / 1000;
	return ((int)(now_ms - start_ms));
}

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
	usleep(100000);
	printf("timestamp: %d ms\n", get_timestamp(now));
	return (0);
}
