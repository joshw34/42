#include "../inc/so_long.h"

int	main(void)
{
	void	*init = mlx_init();
	void	*window = mlx_new_window(init, 500, 500, "Test Window");
	void	*background = mlx_new_image(init, 500, 500);
	

	sleep(5);
	return (0);
}