#include "../../inc/pipex.h"

static	char	*set_cmd_path(char *cmd, char **paths)
{
	char	*result;
	int		i;

	i = 0;
	while (paths[i])
	{
		result = ft_strjoin(paths[i], cmd);
		if (access(result, X_OK) == 0)
			return(result);
		else
			free(result);
		i++;
	}
	return (NULL);
}

static	void	cmd_and_path(char **args, char **env, t_data *data)
{
	char	**paths;

	paths = get_paths(env);
	data->cmd1 = ft_split(args[1], ' ');
	data->cmd1_path = set_cmd_path(data->cmd1[0], paths);
	if (data->cmd1_path == NULL)
	{
		perror("Cmd1");
		free_array(paths);
		free_data_struct(data);
		exit(EXIT_FAILURE);
	}
	data->cmd2 = ft_split(args[2], ' ');
	data->cmd2_path = set_cmd_path(data->cmd2[0], paths);
	if (data->cmd2_path == NULL)
	{
		perror("Cmd2");
		free_array(paths);
		free_data_struct(data);
		exit(EXIT_FAILURE);
	}
	free_array(paths);
}

static	void	file_access(char **args, t_data *data)
{
	if (access(args[0], R_OK) == -1)
	{
		perror("Infile");
		free_data_struct(data);
		exit(EXIT_FAILURE);
	}
	if (access(args[3], W_OK) == -1)
	{
		perror("Outfile");
		free_data_struct(data);
		exit(EXIT_FAILURE);
	}
	data->infile = args[0];
	data->outfile = args[3];
}

static	void	arg_count(int count, t_data *data)
{
	if (count != 4)
	{
		if (count < 4)
			ft_putstr_fd("ERROR: Not enough arguments\n", 2);
		if (count > 4)
			ft_putstr_fd("Error: Too many arguments\n", 2);
		free_data_struct(data);
		exit(EXIT_FAILURE);
	}
}

void	populate_struct(int count, char **args, char **env, t_data *data)
{
	(void)env;
	arg_count(count - 1, data);
	file_access(args + 1, data);
	cmd_and_path(args + 1, env, data);
}
