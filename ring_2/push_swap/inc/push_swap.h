#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					current_index;
	int					push_cost;
	bool				top_half;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;

}	t_stack_node;

char	**split_argv(char *arg_list);

#endif