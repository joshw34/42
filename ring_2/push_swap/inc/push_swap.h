/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:27:53 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/19 17:26:36 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	long				nbr;
	int					current_index;
	int					push_cost;
	bool				top_half;
	bool				cheapest;
	struct s_node	*target_node;
	struct s_node	*prev;
	struct s_node	*next;

}	t_node;

/* error_checking.c */
bool	check_nbr_repeat(t_node *stack);
bool	check_format_error(char **input);

/* free_quit.c */
void	quit_error(void);
void	free_stack(t_node **stack);
void	free_argv(char **argv);
void	quit_error_free(t_node **stack, char **argv, int start);

/* create_stacks.c */
bool	create_stack_a(t_node **stack, char **input, int start);
void	create_stack_b(t_node **a, t_node **b);

/* node_utils.c */
t_node	*find_cheapest(t_node *stack);
int		count_nodes(t_node *stack);
t_node	*last_node(t_node *node);
bool	add_node(t_node **stack, long nbr);

/* push_cost.c */
void	set_cost(t_node *src, t_node *dest);

/* target_node.c */
void	target_a_to_b(t_node *a, t_node *b);

/* index_half.c */
void	curr_index_top_half(t_node *stack);

/* swap.c */
void	sa_sb(t_node **stack, char op);
void	ss(t_node	**a, t_node **b);

/* rotate.c */
void	ra_rb(t_node **stack, char op, int reps);
void	rr(t_node **a, t_node **b, int reps);

/* rev_rotate.c */
void	rra_rrb(t_node **stack, char op, int reps);
void	rrr(t_node **a, t_node **b, int reps);

/* push.c */
void	pa_pb(t_node **src, t_node **dest, char to);

/* sort.c */
void	sort(t_node **a, t_node **b);

/* check_stacks.c */
bool	check_stacks(t_node *a, t_node *b);

/* three_node_sort.c */
void	three_node_sort(t_node **stack);

/* full_sort.c */
void	full_sort(t_node **a, t_node **b);

/* push_a_to_b.c */
void	push_a_to_b(t_node **a, t_node **b);

/* TESTING */
void	print_stack(t_node *node);

#endif