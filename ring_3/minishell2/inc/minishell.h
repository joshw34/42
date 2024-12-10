/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:19:11 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/10 13:12:06 by jwhitley         ###   ########.fr       */
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

# define NONE 0
# define S_QUOTE 1
# define D_QUOTE 2

/* STRUCT TYPEDEFS */
typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	int		cmd_n;
	char	*redir_in;
	char	*redir_out;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_tokens
{
	char			*word;
	char			*sep;
	int				i;
	int				quote;
	struct s_tokens	*next;
	struct s_tokens	*prev;
}	t_tokens;

typedef struct s_data
{
	char			*user_input;
	struct s_tokens	*tokens;
	struct s_cmd	*cmds;
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
t_tokens	*get_tokens(t_data *data, char *user_input);

/* token_list_utils.c */
void		token_lstclear(t_tokens *tokens);
void		token_lstadd(t_tokens *tokens, char *word, char *sep);
t_tokens	*token_lstnew(char *word, char *sep);

/* cmd_list.c */
t_cmd		*get_cmds(t_data *data);

/* cmd_list_utils.c */
int			cmd_count(t_tokens *tokens);

/* utils.c */
bool		is_whitespace(char *str);

/* check_builtins.c */
bool		check_builtins(t_data *data);

/* exit.c */
void		exit_cmd(t_data *data);

/* echo.c */
void		echo_cmd(t_data *data);

/* expand_var.c */
void		expand_var(t_data *data, t_tokens *token);

/* expand_var_2.c */
void		remove_fake_var(t_tokens *token, int start, int end);

/* expand_path.c */
void		expand_tilda(t_data *data, t_tokens *token);
void		expand_path(t_tokens *token);

#endif
