#include "../inc/push_swap.h"

void	print_stack(t_node *node)
{
	t_node	*temp;

	temp = node;
	while(temp != NULL)
	{
		ft_printf("Nbr: %d\tInd: %d\tCost: %d\tTop: %d\tCheap: %d\nAdd: %p\tTgt: %p\tPrv: %p\tNxt: %p\n\n", temp->nbr, temp->current_index, temp->push_cost, temp->top_half, temp->cheapest, temp, temp->target_node, temp->prev, temp->next);
		//ft_printf("%d\n", temp->nbr);
		temp = temp->next;
	}
}