#include "../inc/push_swap.h"

bool	create_stack_a(t_stack_node **stack_a, char **input, int start_pos)
{
	int		i;

	i = start_pos;
	if (!check_error(input + start_pos))
		quit_error_free(stack_a, input, start_pos);
	while (input[i])
	{
		if (!add_node(stack_a, ft_atoi(input[i])))
			quit_error_free(stack_a, input, start_pos);
		i++;
	}
	curr_index_top_half(*stack_a);
	if (start_pos == 0)
		free_argv(input);
	return (true);
}
