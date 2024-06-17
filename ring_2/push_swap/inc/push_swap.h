/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:27:53 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/17 17:29:31 by jwhitley         ###   ########.fr       */
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

/* create_stack_a.c */
bool			create_stack_a(t_stack_node **stack, char **input, int start);

/* stack_tools.c */
int				count_nodes(t_stack_node *stack);
void			curr_index_top_half(t_stack_node *stack);
t_stack_node	*last_node(t_stack_node *node);
t_stack_node	*new_node(int nbr);
bool			add_node(t_stack_node **stack, int nbr);

/* stack_tools_2.c */
void			target_a_to_b(t_stack_node *a, t_stack_node *b);

#endif