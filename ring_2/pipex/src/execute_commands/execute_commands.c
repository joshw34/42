#include "../../inc/pipex.h"

static	void	execute_cmd2(t_data *data, int p_fd[])
{
	int	out_fd;
	close(p_fd[1]);
	out_fd = open(data->outfile, O_RDWR);
	if (out_fd == -1)
	{
		close(p_fd[0]);
		free_exit("Outfile Opening: ", data);
	}
	if (dup2(out_fd, STDOUT_FILENO) == -1)
	{
		close(out_fd);
		free_exit("Outfile FD Duplication: ", data);
	}
	close(out_fd);
	if (dup2(p_fd[0], STDIN_FILENO) == -1)
	{
		close(p_fd[0]);
		free_exit("Cmd2 Pipe Input Duplication: ", data);
	}
	close(p_fd[0]);
	if (execve(data->cmd2_path, data->cmd2, data->env) == -1)
		free_exit("Cmd2 Execution Error: ", data);
}

static	void	execute_cmd1(t_data *data, int p_fd[])
{
	int	in_fd;

	close(p_fd[0]);
	in_fd = open(data->infile, O_RDONLY);
	if (in_fd == -1)
	{
		close(p_fd[1]);
		free_exit("Infile Opening: ", data);
	}
	if (dup2(in_fd, STDIN_FILENO) == -1)
	{
		close(in_fd);
		free_exit("Infile FD Duplication: ", data);
	}
	close(in_fd);
	if (dup2(p_fd[1], STDOUT_FILENO) == -1)
	{
		close(p_fd[1]);
		free_exit("Cmd1 Pipe Output Duplication: ", data);
	}
	close(p_fd[1]);
	if(execve(data->cmd1_path, data->cmd1, data->env) == -1)
		free_exit("Cmd1 Execution Error: ", data);
}

void	execute_commands(t_data *data)
{
	int		p_fd[2];
	pid_t	cpid1;
	pid_t	cpid2;

	if (pipe(p_fd) == -1)
		free_exit("Pipe: ", data);
	cpid1 = fork();
	if (cpid1 == -1)
		free_exit("Fork 1: ", data);
	if (cpid1 == 0)
		execute_cmd1(data, p_fd);
	cpid2 = fork();
	if (cpid2 == -1)
		free_exit("Fork 2: ", data);
	if (cpid2 == 0)
		execute_cmd2(data, p_fd);
	close(p_fd[0]);
	close(p_fd[1]);
	waitpid(cpid1, NULL, 0);
	waitpid(cpid2, NULL, 0);
}
