#include "../inc/so_long.h"

static	void	put_image(t_data *data, int a, int b)
{
	int	x;
	int y;

	x = b * 48;
	y = a * 48;
	if (data->map[a][b] == '0')
		mlx_put_image_to_window(data->init, data->win, data->floor, x, y);
	if (data->map[a][b] == '1')
		mlx_put_image_to_window(data->init, data->win, data->wall, x, y);
	if (data->map[a][b] == 'P')
		mlx_put_image_to_window(data->init, data->win, data->player, b *48, y);
	if (data->map[a][b] == 'E' && data->c > 0)
		mlx_put_image_to_window(data->init, data->win, data->exit1, x, y);
	if (data->map[a][b] == 'E' && data->c == 0)
		mlx_put_image_to_window(data->init, data->win, data->exit2, x, y);
	if (data->map[a][b] == 'C')
		mlx_put_image_to_window(data->init, data->win, data->collect, x, y);
}

static	void	draw_map(t_data *data)
{
	int a;
	int b;
	a = 0;
	while (data->map[a])
	{
		b = 0;
		while (data->map[a][b] != '\0')
		{
			put_image(data, a, b);
			b++;
		}
		a++;
	}
}

static	void	init_mlx(t_data *data)
{
	int x;
	int	y;
	int width;
	int	height;

	x = 48;
	y = 48;
	width = data->cols * x;
	height = data->rows * y;
	data->init = mlx_init();
	data->win = mlx_new_window(data->init, width, height, "so_long");
	data->floor = mlx_xpm_file_to_image(data->init, FLOOR, &x, &y);
	data->wall = mlx_xpm_file_to_image(data->init, WALL, &x, &y);
	data->player = mlx_xpm_file_to_image(data->init, PLAYER, &x, &y);
	data->exit1 = mlx_xpm_file_to_image(data->init, EXIT1, &x, &y);
	data->exit2 = mlx_xpm_file_to_image(data->init, EXIT2, &x, &y);
	data->collect = mlx_xpm_file_to_image(data->init, COLLECT, &x, &y);
}

void	run_game(t_data *data)
{
	init_mlx(data);
	draw_map(data);
	sleep(5);
}
