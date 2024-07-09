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

static	void	cmd_and_path(char **args, t_data *data)
{
	char	**paths;

	paths = get_paths(data->env);
	data->cmd1 = ft_split(args[1], ' ');
	data->cmd1_path = set_cmd_path(data->cmd1[0], paths);
	if (data->cmd1_path == NULL)
	{
		free_array(paths);
		free_exit("Cmd1: ", data);
	}
	data->cmd2 = ft_split(args[2], ' ');
	data->cmd2_path = set_cmd_path(data->cmd2[0], paths);
	if (data->cmd2_path == NULL)
	{
		free_array(paths);
		free_exit("Cmd2: ", data);
	}
	free_array(paths);
}

static	void	file_access(char **args, t_data *data)
{
	int	fd;

	if (access(args[0], R_OK) == -1)
		free_exit("Infile: ", data);
	if (access(args[3], F_OK) != -1 && access(args[3], W_OK) == -1)
		free_exit("Outfile: ", data);
	else if (access(args[3], F_OK) == -1)
	{
		fd = open(args[3], O_WRONLY | O_CREAT, 0644);
		if (fd == -1)
		{
			free_exit("Outfile: ", data);
		}
		close(fd);
	}
	data->infile = args[0];
	data->outfile = args[3];
}

static	void	arg_count(int count, t_data *data)
{
	if (count != 4)
	{
		if (count < 4)
			free_exit("Error: Not Enough Arguments", data);
		if (count > 4)
			free_exit("Error: Too Many Arguments", data);
	}
}

void	populate_struct(int count, char **args, char **env, t_data *data)
{
	arg_count(count - 1, data);
	file_access(args + 1, data);
	data->env = env;
	cmd_and_path(args + 1, data);
}
