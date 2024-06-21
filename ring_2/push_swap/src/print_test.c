#include "../inc/push_swap.h"

void	print_stack_a(t_node *node)
{
	t_node	*temp;

	temp = node;
	ft_printf("STACK A\n");
	while(temp != NULL)
	{
		//ft_printf("Nbr: %d\tInd: %d\tCost: %d\tTop: %d\tCheap: %d\tTarget:%d\n", temp->nbr, temp->current_index, temp->push_cost, temp->top_half, temp->cheapest, temp->target_node->nbr);
		ft_printf("%d\n", temp->nbr);
		temp = temp->next;
	}
}

void	print_stack_b(t_node *node)
{
	t_node	*temp;

	temp = node;
	ft_printf("\n\nSTACK B\n");
	while(temp != NULL)
	{
		//ft_printf("Nbr: %d\tInd: %d\tCost: %d\tTop: %d\n", temp->nbr, temp->current_index, temp->push_cost, temp->top_half);
		ft_printf("%d\n", temp->nbr);
		temp = temp->next;
	}
}
