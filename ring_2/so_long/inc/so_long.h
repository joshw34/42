/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:27:53 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/06 12:51:00 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/functions/get_next_line/get_next_line.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define FLOOR "./assets/floor.xpm"
# define WALL "./assets/wall.xpm"
# define PLAYER "./assets/player.xpm"
# define EXIT1 "./assets/exit1.xpm"
# define EXIT2 "./assets/exit2.xpm"
# define COLLECT "./assets/collect.xpm"

typedef struct s_data
{
	void	*init;
	void	*win;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit1;
	void	*exit2;
	void	*collect;
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

/* game.c */
void	run_game(t_data *data);

/* utils.c */
char	*sl_gnl(int fd, char **buffer);
t_data	*init_data_struct(void);

#endif