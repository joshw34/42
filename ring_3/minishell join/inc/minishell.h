/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:19:11 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/07 15:50:35 by jwhitley         ###   ########.fr       */
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
# include <signal.h>

# define NONE 0
# define S_QUOTE 1
# define D_QUOTE 2

# define IN 0
# define OUT 1

# define INFILE 0
# define HEREDOC 1
# define OUTFILE 2
# define APPEND 3

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
	char			*cmd;
	char			**args;
	int				pid;
	int				fd_in;
	int				fd_out;
	int				pipe_fd[2];
	int				cmd_n;
	char			**env;
	struct s_data	*data;
	struct s_redir	*in;
	struct s_redir	*out;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_tokens
{
	char			*word;
	char			*sep;
	int				i;
	int				quote;
	bool			processed;
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

/* builtin_cd.c */
void		change_dir(t_cmd *cmd);

/* builtin_cd_utils.c */
char		*get_realpwd(void);

/* builtin_echo.c */
void		echo_cmd(t_cmd *cmd);

/* builtin_exit.c */
void		exit_cmd(t_data *data);

/* builtin_pwd.c */
void		print_pwd(t_data *data);

/* builtin_var_export.c */
bool		remove_var(t_data *data, char *var);
bool		export_env(t_data *data, char *new_var);

/* builtin_var_export_utils.c */
bool		var_is_valid(char *new_var);

/* builtin_var_get_print.c */
void		print_env(t_data *data);
char		*get_var(char **env, char *var);

/* builtin_var_utils.c */
char		*find_var(char **env, char *var);

/* token_list.c */
t_tokens	*get_tokens(t_data *data, char *user_input);

/* token_list_utils.c */
void		token_lstclear(t_tokens *tokens);
void		token_lstadd(t_tokens *tokens, char *word, char *sep);
int	quote_status(char *str);
t_tokens	*token_lstnew(char *word, char *sep);

/* cmd_list.c */
void		cmd_list_clear(t_cmd *cmds);
t_cmd		*get_cmds(t_data *data);

/* cmd_list_utils.c */
char		*parse_cmd(t_tokens *tokens, int start, int end);
int			cmd_find_end(int start, t_tokens *tokens);
int			cmd_count(t_tokens *tokens);

/* utils.c */
char		*parse_argv(char **argv);
bool		is_whitespace(char *str);

/* check_builtins.c */
bool		check_builtins(t_cmd *cmd);

/* expand_var.c */
void		expand_var(t_data *data, t_tokens *token);

/* expand_var_2.c */
void		remove_fake_var(t_tokens *token, int start, int end);

/* expand_path.c */
void		expand_tilde(t_data *data, t_tokens *token);
void		expand_path(t_tokens *token);

/* redir_list_input.c */
void		redir_list_clear(t_redir *redir);
t_redir		*get_input_redir(t_tokens *tokens, int start, int end);

/* redir_list_output.c */
t_redir		*get_output_redir(t_tokens *tokens, int start, int end);

/* DEBUG_FUNCS.c */
void		DB_print_array(char **array);
void		DB_print_tokens(t_data *data);
void		DB_print_cmds(t_data *data);
void		DB_print_output_redir(t_redir *output);
void		DB_print_input_redir(t_redir *input);

/* fetch_path_command.c */
char	**get_path_array(char **env, char *arg);
int		exec_command(char **env, char **arg);
/* free_memory_function.c */
void	free_2d_array(char **array);
/* redirection_handling.c */
void	redirection_file_checking_and_selection
			(t_cmd **command_array, int direction);
void	redirection_and_execution(t_cmd *command_array);
void	redirecting_std_input(t_cmd *command_array);
void	redirecting_std_output(t_cmd *command_array);
/* redirection_file_opening.c */
int	open_file(t_redir *redirection);
/* execution_handling.c */
int		execute_command(t_cmd *command_array);
void	processing_commands(t_cmd *command_array);
void	shell_execution(t_cmd *command_array);
/* multi_procesing.c */
void	waiting_sons_processes(t_cmd *command_array, int *status);
/*builtin_execution_handling.c*/
bool	is_a_builtin(t_cmd *cmd);
int redirection_and_execution_builtin(t_cmd *cmd);

/* split_new.c */
char 	**ft_split_new(char const *s, char c);

/* split_new_utils.c */
bool 	in_quotes(const char *str, int i);
int		find_end_quote(const char *str, int i);
int		find_next_string(const char *str, char c);

#endif
