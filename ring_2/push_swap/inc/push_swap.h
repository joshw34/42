/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:27:53 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/18 17:56:43 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
bool			check_error(char **input);

/* free_quit.c */
void			quit_error(void);
void			free_stack(t_stack_node **stack);
void			free_argv(char **argv);
void			quit_error_free(t_stack_node **stack, char **argv, int start);

/* create_stacks.c */
bool			create_stack_a(t_stack_node **stack, char **input, int start);
void			create_stack_b(t_stack_node **a, t_stack_node **b);

/* node_utils.c */
int				count_nodes(t_stack_node *stack);
t_stack_node	*last_node(t_stack_node *node);
bool			add_node(t_stack_node **stack, int nbr);

/* push_cost.c */
void			set_cost(t_stack_node *src, t_stack_node *dest);

/* target_node.c */
void			target_a_to_b(t_stack_node *a, t_stack_node *b);

/* index_half.c */
void			curr_index_top_half(t_stack_node *stack);

/* swap.c */
void			sa_sb(t_stack_node **stack);
void			ss(t_stack_node	**a, t_stack_node **b);

/* rotate.c */
void			ra_rb(t_stack_node **stack);
void			rr(t_stack_node **a, t_stack_node **b);

/* rev_rotate.c */
void			rra_rrb(t_stack_node **stack);
void			rrr(t_stack_node **a, t_stack_node **b);

/* push.c */
void			pa_pb(t_stack_node **src, t_stack_node **dest);

/* sort.c */
void			sort(t_stack_node **a, t_stack_node **b);

/* check_stacks.c */
bool	check_stacks(t_stack_node *a, t_stack_node *b);




/* TESTING */
void	print_stack(t_stack_node *node);

#endif