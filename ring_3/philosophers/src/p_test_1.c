#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*thread_test(void *arg)
{
	sleep(5);
	char *s = (char *)arg;
	printf("%s\n", s);
	pthread_exit(NULL);
}

void	test_function(char **args)
{
	int i = 1;
	pthread_t	new_thread_1;

	while(args[i])
	{
		printf("Creating new_thread_%d\n", i);
		pthread_create(&new_thread_1, NULL, &thread_test, (void *)args[i]);
		pthread_join(new_thread_1, NULL);
		printf("new_thread_%d exited\n", i);
		sleep(5);
		i++;
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	printf("Waiting 5 seconds\n");
	sleep(5);
	test_function(argv + 1);
	return (0);
}
