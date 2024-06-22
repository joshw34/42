#include "../inc/push_swap.h"


void	print_stack_b(t_node *b)
{
	t_node	*temp_b;

	temp_b = b;
	ft_printf("\n\nSTACK B\n");
	while(temp_b != NULL)
	{
		ft_printf("Nbr: %d\tAdd: %p\tPrev: %p\tNext: %p\n", temp_b->nbr, temp_b, temp_b->prev, temp_b->next);
		temp_b = temp_b->next;
	}
}

void	print_stack(t_node *a, t_node *b)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = a;
	temp_b = b;
	ft_printf("\n\nSTACK B\n");
	while(temp_b != NULL)
	{
		ft_printf("Nbr: %d\tAdd: %p\tPrev: %p\tNext: %p\tTgt: %p\n", temp_b->nbr, temp_b, temp_b->prev, temp_b->next, temp_b->target_node);
		temp_b = temp_b->next;
	}
	ft_printf("\n\nSTACK A\n");
	while(temp_a != NULL)
	{
		ft_printf("Nbr: %d\tAdd: %p\tPrev: %p\tNext: %p\n", temp_a->nbr, temp_a, temp_a->prev, temp_a->next);
		temp_a = temp_a->next;
	}
}

void	print_final(t_node *final)
{
	while (final != NULL)
	{
		ft_printf("%d\n", final->nbr);
		final = final->next;
	}
}

