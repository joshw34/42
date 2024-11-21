/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:19:11 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/21 16:04:31 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/history.h>
# include <readline/readline.h>

/* STRUCT TYPEDEFS */
typedef enum e_tok_list
{
	WORD = 1,
	PIPE,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tok_list;

typedef struct s_tokens
{
	char			*word;
	char			*sep;
	int				i;
	struct s_reader	*next;
	struct s_reader	*prev;
}	t_tokens;

typedef struct s_data
{
	char			*user_input;
	struct s_tokens	*tokens;
	char			**env;
}	t_data;

/* FUNCTION PROTOTYPES*/
/* init_data_struct.c */
t_data	*init_data_struct(char **env);

/* free.c */
void	free_data_struct(t_data *data, bool keep_env);
void	free_array(char **array);

/* get_input.c */
char	*get_input(t_data *data);

/* var_get_print.c */
void	print_env(t_data *data);
char	*get_var(char **env, char *var);

/* var_export.c */
bool	export_env(t_data *data, char *new_var);

/* var_export_utils.c */
bool	var_is_valid(char *new_var);

/* var_utils.c */
char	*find_var(char **env, char *var);

#endif
