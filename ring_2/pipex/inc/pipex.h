/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:27:53 by jwhitley          #+#    #+#             */
/*   Updated: 2024/07/09 19:29:53 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <stdarg.h>

typedef	struct s_pipe
{
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**env;
}	t_data;

/* parse_check_input.c */
void	populate_struct(int count, char **args, char **env, t_data *data);

/* free.c */
void	free_data_struct(t_data *data);
void	free_array(char **array);
void	free_exit(char *message, t_data *data);

/* utils.c */
char	**get_paths(char **env);

/* error_print.c */
int		error_print(const char *str, ...);

/* execute_commands.c */
//void	execute_commands(t_data *data);

#endif