#include "test_header.h"

void	withdraw(int amount, t_bank *account)
{
	pthread_mutex_lock(&account->lock);
	if (amount <= account->balance)
	{
		account->balance -= amount;
		printf("-%d ", amount);
	}
	else
		printf("0 ");
	pthread_mutex_unlock(&account->lock);
}

void	deposit(int amount, t_bank *account)
{
	pthread_mutex_lock(&account->lock);
	account->balance += amount;
	printf("%d ", amount);
	pthread_mutex_unlock(&account->lock);
}

void	*transaction(void *arg)
{
	int		amount = 0;
	int		i = 0;
	t_bank	*account = (t_bank *)arg;

	while (i < 100)
	{
		amount = rand() % 100;
		deposit(amount, account);
		if (rand() % 2 == 0)
			deposit(amount, account);
		else
			withdraw(amount, account);
		i++;
	}
	pthread_exit(NULL);
}

int	main(int argc, char **argv)
{
	int			i = 0;
	int			num_thread = atoi(argv[1]);
	pthread_t	threads[num_thread];
	t_bank		account;
	
	account.balance = 0;
	pthread_mutex_init(&account.lock, NULL);
	srand(time(NULL));
	(void)argc;

	while (i < num_thread)
	{
		pthread_create(&threads[i], NULL, transaction, &account);
		i++;
	}

	i = 0;
	
	while (i < num_thread)
	{
		pthread_join(threads[i], NULL);
		i++;
	}

	printf("\nFINAL BALANCE: %d\n", account.balance);

	return (0);
}
