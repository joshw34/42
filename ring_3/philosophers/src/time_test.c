#include <sys/time.h>
#include <stdio.h>

int	main(void)
{
	struct timeval	current_time;
	gettimeofday(&current_time, NULL);
	printf("seconds: %ld\nmicroseconds: %ld", current_time.tv_sec, current_time.tv_usec);
	return (0);
}
