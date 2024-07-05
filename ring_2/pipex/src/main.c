#include "../inc/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	populate_struct(argc, argv, env, data);
	return (0);
}
