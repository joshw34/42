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

/* error_checking.c */
bool	check_error(char **input);
bool	check_format(char *str);
bool	check_repeat(char *str, char **input);

/* free_quit.c*/
void	quit_error(void);
void	quit_error_free(char **argv, int start_pos);
void	free_argv(char **argv);

/* create_stack_a.c */
bool	create_stack_a(t_stack_node **stack_a, char **input, int start_pos);

/* stack_tools.c */

#endif