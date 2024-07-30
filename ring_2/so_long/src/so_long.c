#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	parse_map(argc, argv[1], data);
	return (0);
}


/*void	*init = mlx_init();
	void	*window = mlx_new_window(init, 500, 500, "Test Window");
	int x = 500;
	int y = 500;
	void	*background = mlx_xpm_file_to_image(init, "./assets/bg.xpm", &x, &y);
	if (background == NULL)
		return (ft_printf("FUCKED IT"), 1);
	mlx_put_image_to_window(init, window, background, 0, 0);
	mlx_string_put(init, window, 250, 250, 150210055, "FUCK");
	sleep(5);*/