/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:19:11 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/14 15:08:09 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <signal.h>
# include <stdarg.h>
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
# define UNCLOSED 3

# define IN 0
# define OUT 1

# define INFILE 0
# define HEREDOC 1
# define OUTFILE 2
# define APPEND 3
# define WORD 4
# define PIPE 5

# define ERROR_1 "Minishell: Error: Unexpected EOF: Unclosed "
# define ERROR_2 "Minishell: Error: Unexpected newline"
# define ERROR_3 "Minishell: Error: Unexpected token "

# define HERE_DOC_PATH "./here_doc_temp" 

/* STRUCT TYPEDEFS */
typedef struct s_redir
{
	char			*filename;
	int				direction;
	int				mode;
	int				fd;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char				*cmd;
	char				**args;
	int					pid;
	int					fd_in;
	int					fd_out;
	int					pipe_fd[2];
	int					cmd_n;
	char				**env;
	struct s_data		*data;
	struct s_redir		*in;
	struct s_redir		*out;
	struct s_cmd		*prev;
	struct s_cmd		*next;
}	t_cmd;

typedef struct s_tokens
{
	char				*word;
	char				*sep;
	int					i;
	int					type;
	bool				processed;
	struct s_tokens		*next;
	struct s_tokens		*prev;
}	t_tokens;

typedef struct s_data
{
	char				*user_input;
	struct s_tokens		*tokens;
	struct s_cmd		*cmds;
	char				**env;
	struct sigaction	sig_act;
}	t_data;

extern int	g_last_signal;

/* FUNCTION PROTOTYPES*/
/* init_data_struct.c */
t_data					*init_data_struct(char **env);

/* free.c */
void					free_data_struct(t_data *data, bool keep_env);
void					free_array(char **array);
void					multi_free(int count, ...);

/* free_list_clear.c */
void					token_lstclear(t_tokens *tokens);

/* get_input.c */
bool					valid_input(char *input);
char					*get_input(t_data *data);

/* process_user_input.c */
bool					process_user_input(t_data *data);

/* token_splitter.c */
char					**split_tokens(char **input);

/* token_check_spaces.c */
int						separator_is_spaced(char *input, int i);

/* token_add_spaces. */
void					add_spaces(char **input, int *index, int new_spaces);

/* token_expand.c */
bool					expand_tokens(t_tokens *token);

/* token_syntax.c */
bool					sep_syntax(t_tokens * token);
bool					word_syntax(char *str);

/* token_expand_utils.c */

/* token_list.c */
bool					token_list(t_data *data, char **split);

/* token_utils.c */
void					set_token_type(t_tokens *token);
bool					is_a_separator(char c);

/* signal_handling.c */
void					standard_behavior(int sigint);
void					here_doc_open_behavior(int sig);

/* builtin_cd.c */
void					change_dir(t_cmd *cmd);

/* builtin_cd_utils.c */
void					go_home_sysenv(t_data *data);
void					go_home_expand_sysenv(t_data *data, char *new_dir);

/* builtin_var_export.c */
bool					export_env(t_data *data, char *new_var);
bool					remove_var(t_data *data, char *var);

/* builtin_var_export_utils.c */
bool					var_is_valid(char *new_var);

/* builtin_var_get_print.c */
void					print_env(t_data *data);
char					*get_var(char **env, char *var);

/* builtin_var_utils.c */
char					*find_var(char **env, char *var);

/* utils.c */
bool					is_whitespace(char *str);
char					*get_realpwd(void);

/* DEBUG_FUNCS.c */
void					db_print_array(char **array);
void					db_print_tokens(t_data *data);
void					db_print_cmds(t_data *data);
void					db_print_output_redir(t_redir *output);
void					db_print_input_redir(t_redir *input);

#endif
