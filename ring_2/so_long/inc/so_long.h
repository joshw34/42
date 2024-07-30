/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:27:53 by jwhitley          #+#    #+#             */
/*   Updated: 2024/07/30 18:05:30 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../libft/functions/get_next_line/get_next_line.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct s_data
{
	void	*init;
	void	*win;
	char	**map;
	int		rows;
	int		cols;
}	t_data;


/* parse_map.c */
void	check_argc_ext(int argc, char *map, t_data *data);
void	parse_map(int argc, char *map, t_data *data);

/* free_data.c */
void	free_data(t_data *data);
void	free_array(char **array);
void	error_exit(t_data *data);

/* utils.c */
char	*sl_gnl(int fd, char **buffer);

#endif