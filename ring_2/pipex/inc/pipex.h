/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:27:53 by jwhitley          #+#    #+#             */
/*   Updated: 2024/07/05 19:00:52 by jwhitley         ###   ########.fr       */
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

typedef	struct s_pipe
{
	char	*infile;
	char	**arg1;
	char	**arg2;
	char	*outfile;
	char	**env;
	char	*arg1_path;
	char	*arg2_path;
}	t_data;

/* input_check.c */
void	populate_struct(int count, char **args, char **env, t_data data);

/* free.c */
void	free_data_struct(t_data *data);
void	free_array(char **array);

#endif