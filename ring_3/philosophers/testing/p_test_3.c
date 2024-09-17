#include "test_header.h"

void	*thread_10(void *arg)
{
	(void)arg;
	printf("Thread 10 sleeping 5 seconds\n\n");
	sleep(5);
	printf("Exiting thread 10\n\n");
	sleep(5);
	pthread_exit(NULL);
}

void	*thread_9(void *arg)
{
	pthread_t	t_10;

	(void)arg;
	printf("Thread 9 sleeping 5 seconds\n\n");
	sleep(5);
	printf("Starting thread 10\n\n");
	pthread_create(&t_10, NULL, &thread_10, NULL);
	pthread_join(t_10, NULL);
	printf("Exiting thread 9\n\n");
	sleep(5);
	pthread_exit(NULL);
}

void	*thread_8(void *arg)
{
	pthread_t	t_9;

	(void)arg;
	printf("Thread 8 sleeping 5 seconds\n\n");
	sleep(5);
	printf("Starting thread 9\n\n");
	pthread_create(&t_9, NULL, &thread_9, NULL);
	pthread_join(t_9, NULL);
	printf("Exiting thread 8\n\n");
	sleep(5);
	pthread_exit(NULL);
}

void	*thread_7(void *arg)
{
	pthread_t	t_8;

	(void)arg;
	printf("Thread 7 sleeping 5 seconds\n\n");
	sleep(5);
	printf("Starting thread 8\n\n");
	pthread_create(&t_8, NULL, &thread_8, NULL);
	pthread_join(t_8, NULL);
	printf("Exiting thread 7\n\n");
	sleep(5);
	pthread_exit(NULL);
}

void	*thread_6(void *arg)
{
	pthread_t	t_7;

	(void)arg;
	printf("Thread 6 sleeping 5 seconds\n\n");
	sleep(5);
	printf("Starting thread 7\n\n");
	pthread_create(&t_7, NULL, &thread_7, NULL);
	pthread_join(t_7, NULL);
	printf("Exiting thread 6\n\n");
	sleep(5);
	pthread_exit(NULL);
}

void	*thread_5(void *arg)
{
	pthread_t	t_6;

	(void)arg;
	printf("Thread 5 sleeping 5 seconds\n\n");
	sleep(5);
	printf("Starting thread 6\n\n");
	pthread_create(&t_6, NULL, &thread_6, NULL);
	pthread_join(t_6, NULL);
	printf("Exiting thread 5\n\n");
	sleep(5);
	pthread_exit(NULL);
}

void	*thread_4(void *arg)
{
	pthread_t	t_5;

	(void)arg;
	printf("Thread 4 sleeping 5 seconds\n\n");
	sleep(5);
	printf("Starting thread 5\n\n");
	pthread_create(&t_5, NULL, &thread_5, NULL);
	pthread_join(t_5, NULL);
	printf("Exiting thread 4\n\n");
	sleep(5);
	pthread_exit(NULL);
}

void	*thread_3(void *arg)
{
	pthread_t	t_4;

	(void)arg;
	printf("Thread 3 sleeping 5 seconds\n\n");
	sleep(5);
	printf("Starting thread 4\n\n");
	pthread_create(&t_4, NULL, &thread_4, NULL);
	pthread_join(t_4, NULL);
	printf("Exiting thread 3\n\n");
	sleep(5);
	pthread_exit(NULL);
}

void	*thread_2(void *arg)
{
	pthread_t	t_3;

	(void)arg;
	printf("Thread 2 sleeping 5 seconds\n\n");
	sleep(5);
	printf("Starting thread 3\n\n");
	pthread_create(&t_3, NULL, &thread_3, NULL);
	pthread_join(t_3, NULL);
	printf("Exiting thread 2\n\n");
	sleep(5);
	pthread_exit(NULL);
}

void	*thread_1(void *arg)
{
	pthread_t	t_2;

	(void)arg;
	printf("Thread 1 sleeping 5 seconds\n\n");
	sleep(5);
	printf("Starting thread 2\n\n");
	pthread_create(&t_2, NULL, &thread_2, NULL);
	pthread_join(t_2, NULL);
	printf("Exiting thread 1\n\n");
	sleep(5);
	pthread_exit(NULL);
}

void	start_test(void)
{
	pthread_t	t_1;

	printf("Starting thread 1\n\n");
	pthread_create(&t_1, NULL, &thread_1, NULL);
	pthread_join(t_1, NULL);
}

int	main(void)
{
	printf("Sleeping 5 seconds\n\n");
	sleep(5);
	start_test();
	printf("All threads exited, program sleeping 5 seconds\n");
	sleep(5);
	return (0);
}
