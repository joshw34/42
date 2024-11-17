/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:19:11 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/18 00:04:08 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct	s_single
{
	char	*path;
	char	**args;
	pid_t	pid;
}	t_single;

/* FUNCTION PROTOTYPES */
/* utils.c */
char	*get_path(char **args, char *paths);
char	**get_args(char *input);
char	*get_prompt(void);

/* read_input.c */
void	read_input(char *input, char **env);

/* run_sinlge_command.c */
void	run_single_command(char *input, char **env);

/* check_args.c */
bool	check_args(char **args);

/* free_exit.c */
void	free_single_struct(t_single *data);
void	user_exit(char *input);
void	free_array(char **array);
#endif
