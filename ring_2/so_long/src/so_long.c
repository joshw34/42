#include <mlx.h>
#include "../inc/so_long.h"

int	main(void)
{
	void	*init = mlx_init();
	mlx_new_window(init, 100, 100, "Test Window");

	sleep(5);
	return (0);
}