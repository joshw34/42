#include "../inc/push_swap.h"

void	quit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	quit_error_free(t_stack_node **stack, char **argv, int start)
{
	if (start == 0)
		free_argv(argv);
	if (*stack != NULL)
		free_stack(stack);
	quit_error();
}
