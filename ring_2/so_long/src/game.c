#include "../inc/so_long.h"

void	run_game(t_data *data)
{
	/*data->init = malloc(sizeof(void *));
	data->win = malloc(sizeof(void *));*/
	data->init = mlx_init();
	data->win = mlx_new_window(data->init, 500, 500, "Test Window");
	mlx_destroy_window(data->init, data->win);
	mlx_destroy_display(data->init);
	free(data->init);
}