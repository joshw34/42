#include "test_header.h"

typedef	struct s_mutex_test
{
	int				counter;
	pthread_mutex_t	mutex;
} t_mutex_data;


void	*increment_counter(void *arg)
{
	t_mutex_data	*data = arg;
	int				i = 0;

	while (i < 1000000)
	{
		data->counter++;
		i++;
	}
	pthread_exit(NULL);
}

int	main(void)
{
	t_mutex_data	data;
	pthread_t		t_1, t_2;

	data.counter = 0;
	
	pthread_create(&t_1, NULL, increment_counter, &data);
	pthread_create(&t_2, NULL, increment_counter, &data);

	pthread_join(t_1, NULL);
	pthread_join(t_2, NULL);

	printf("Final Counter: %d\n", data.counter);

	return (0);
}
