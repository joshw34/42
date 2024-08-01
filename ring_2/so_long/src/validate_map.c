#include "../inc/so_long.h"

static	void	check_possible(t_data *data, char **temp, int r, int c)
{
	if (r < 0 || r >= data->rows || c < 0 || c >= data->cols)
		return ;
	(void)temp;
	if (temp[r][c] == '1' || temp[r][c] == 'X')
		return ;
	else if (temp[r][c] == 'C')
		data->c--;
	else if (temp[r][c] == 'E')
		data->e--;
	temp[r][c] = 'X';
	check_possible(data, temp, r, c + 1);
	check_possible(data, temp, r, c - 1);
	check_possible(data, temp, r + 1, c);
	check_possible(data, temp, r - 1, c);
}

static	char	**init_temp_map_array(t_data *data)
{
	char	**temp;
	int		i;

	temp = (char **)malloc((data->rows +1) * sizeof(char *));
	if (!temp)
	{
		perror("Error\nMalloc failed\n");
		error_exit(data, "");
	}
	i = 0;
	while (i < data->rows)
	{
		temp[i] = ft_strdup(data->map[i]);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

void	validate_map(t_data *data)
{
	int		r;
	int		c;
	char	**temp;

	r = data->p_row;
	c = data->p_col;
	temp = init_temp_map_array(data);
	check_possible(data, temp, r, c);
	free_array(temp);
	if (data->c > 0)
		error_exit(data, "Error\nCollectible not reachable\n");
	if (data->e > 0)
		error_exit(data, "Error\nExit not reachable\n");
}
