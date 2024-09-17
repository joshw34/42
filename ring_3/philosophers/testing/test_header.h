#ifndef TEST_HEADER_H
# define	TEST_HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef	struct s_mutex_test
{
	int				counter;
	pthread_mutex_t	mutex;
} t_mutex_data;

typedef struct s_bank
{
	int				balance;
	pthread_mutex_t	lock;
} t_bank;

#endif