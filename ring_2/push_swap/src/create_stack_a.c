#include "../inc/push_swap.h"

bool	create_stack_a(t_stack_node **stack_a, char **input, int start_pos)
{
	//int		i;
	//long	num;

	//i = 1;
	(void)stack_a;
	if (!check_error(input + start_pos))
	{
		quit_error_free(input, start_pos);
		return (false);
	}
	if (start_pos == 0)
		free_argv(input);
	return (true);
}
