/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:19:11 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/02 13:55:48 by jwhitley         ###   ########.fr       */
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

typedef struct s_cmd
{
	char	*cmd;
	char	*args;
	int		cmd_n;
	bool	pipe_in;
	bool	pipe_out;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_tokens
{
	char			*word;
	char			*sep;
	int				i;
	struct s_tokens	*next;
	struct s_tokens	*prev;
}	t_tokens;

typedef struct s_data
{
	char			*user_input;
	struct s_tokens	*tokens;
	char			**env;
}	t_data;

/* FUNCTION PROTOTYPES*/
/* init_data_struct.c */
t_data		*init_data_struct(char **env);

/* free.c */
void		free_data_struct(t_data *data, bool keep_env);
void		free_array(char **array);

/* get_input.c */
char		*get_input(t_data *data);

/* var_get_print.c */
void		print_env(t_data *data);
char		*get_var(char **env, char *var);

/* var_export.c */
bool		remove_var(t_data *data, char *var);
bool		export_env(t_data *data, char *new_var);

/* var_export_utils.c */
bool		var_is_valid(char *new_var);

/* var_utils.c */
char		*find_var(char **env, char *var);

/* cd.c */
void		change_dir(t_data *data, char *new_dir);

/* cd_utils.c */
char		*get_realpwd(void);

/* pwd.c */
void		print_pwd(t_data *data);

/* token_list.c */
t_tokens	*get_tokens(char *user_input);

/* token_list_utils.c */
void		token_lstclear(t_tokens *tokens);
void		token_lstadd(t_tokens *tokens, char *word, char *sep);
t_tokens	*token_lstnew(char *word, char *sep);

/* cmd_list.c */
t_cmd		*get_cmds(t_data *data);

/* utils.c */
bool		is_whitespace(char *str);

/* check_builtins.c */
bool		check_builtins(t_data *data);

/* exit.c */
void		exit_cmd(t_data *data);

/* echo.c */
void		echo_cmd(t_data *data);

#endif
