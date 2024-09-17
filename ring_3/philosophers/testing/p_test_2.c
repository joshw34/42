#include "test_header.h"

void	*thread_test_3(void *arg)
{
	sleep(5);
	(void)arg;
	printf("t_3 running\n");
	sleep(5);
	pthread_exit(NULL);
}

void	*thread_test_2(void *arg)
{
	pthread_t t_3;

	sleep(5);
	(void)arg;
	printf("Creating t_3\n");
	pthread_create(&t_3, NULL, &thread_test_3, NULL);
	pthread_join(t_3, NULL);
	printf("t_3 exited\n");
	sleep(5);
	pthread_exit(NULL);
}

void	*thread_test_1(void *arg)
{
	pthread_t t_2;

	sleep(5);
	(void)arg;
	printf("Creating t_2\n");
	pthread_create(&t_2, NULL, &thread_test_2, NULL);
	pthread_join(t_2, NULL);
	printf("t_2 exited\n");
	sleep(5);
	pthread_exit(NULL);
}

void	thread_test_0(void)
{
	pthread_t t_1;

	sleep(5);
	printf("Creating t_1\n");
	pthread_create(&t_1, NULL, &thread_test_1, NULL);
	pthread_join(t_1, NULL);
	printf("t_1 exited\n");
	sleep(5);
}

int	main(void)
{
	printf("Starting test\n");
	thread_test_0();
	return (0);
}
