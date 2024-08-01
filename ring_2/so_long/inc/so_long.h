/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:27:53 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/01 12:11:02 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/functions/get_next_line/get_next_line.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	void	*init;
	void	*win;
	char	**map;
	int		rows;
	int		cols;
	int		p_row;
	int		p_col;
	int		c;
	int		e;
	int		p;
}	t_data;

/* parse_map.c */
void	parse_map(int argc, char *map, t_data *data);

/* free_data.c */
void	free_data(t_data *data);
void	free_array(char **array);
void	error_exit(t_data *data, char *message);

/* check_map.c */
void	check_map_data(t_data *data);

/* validate_map.c */
void	validate_map(t_data *data);

/* utils.c */
char	*sl_gnl(int fd, char **buffer);
t_data	*init_data_struct(void);

#endif