#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	//t_stack_node	*b;
	int				start_pos;

	a = NULL;
	//b = NULL;
	start_pos = 1;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		quit_error();
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		start_pos = 0;
	}
	create_stack_a(&a, argv, start_pos);
	/*while (a != NULL)
	{
		ft_printf("Nbr: %d, Ind: %d, Top: %d, Current: %p, Next: %p, Prev: %p\n", a->nbr, a->current_index, a->top_half, a, a->next, a->prev);
		ft_printf("\n");
		a = a->next;
	}*/
	free_stack(&a);
	return (0);
}
