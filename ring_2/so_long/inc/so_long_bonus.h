/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:27:53 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/28 16:54:35 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../libft/functions/get_next_line/get_next_line.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define FLOOR "./assets/floor.xpm"
# define WALL "./assets/wall.xpm"
# define PLAYER_U "./assets/player_u.xpm"
# define PLAYER_D "./assets/player_d.xpm"
# define PLAYER_R "./assets/player_r.xpm"
# define PLAYER_L "./assets/player_l.xpm"
# define EXIT_C "./assets/exit_c.xpm"
# define EXIT_O "./assets/exit_o.xpm"
# define COLLECT "./assets/collect.xpm"
# define FIRE "./assets/fire.xpm"

# define W 119
# define A 97
# define S 115
# define D 100

# define UP 65362
# define LT 65361
# define DN 65364
# define RT 65363

# define ESC 65307

typedef struct s_m_data
{
	int	rows;
	int	cols;
	int	p_row;
	int	p_col;
	int	e_row;
	int	e_col;
	int	c;
	int	e;
	int	p;
	int	moves;
}	t_m_data;

typedef struct s_data
{
	void		*init;
	void		*win;
	void		*floor;
	void		*wall;
	void		*player_u;
	void		*player_d;
	void		*player_r;
	void		*player_l;
	void		*exit_c;
	void		*exit_o;
	void		*collect;
	void		*fire;
	char		**map;
	t_m_data	*m_data;
}	t_data;

/* parse_map.c */
void	parse_map(int argc, char *map, t_data *data);

/* check_map.c */
void	check_map_data(t_data *data);

/* validate_map.c */
void	validate_map(t_data *data);

/* game.c */
void	run_game(t_data *data);

/* game_draw.c */
void	print_moves(t_data *data);
void	put_image(t_data *data, int a, int b);
void	init_map(t_data *data);

/* game_hooks.c */
int		win_close(t_data *data);
int		expose_win(t_data *data);
int		key(int keysym, t_data *data);

/* game_move.c */
void	left_right(t_data *data, int row, int col, int keysym);
void	up_down(t_data *data, int row, int col, int keysym);

/* utils.c */
char	*sl_gnl(int fd, char **buffer);
t_data	*init_data_struct(void);

/* free_data.c */
void	free_data(t_data *data);
void	free_array(char **array);
void	success_exit(t_data *data, char *message);
void	error_exit(t_data *data, char *message);

#endif