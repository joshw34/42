#include "../../inc/pipex.h"

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
		ex_1;
	cpid2 = fork();
	if (cpid2 == -1)
		free_exit("Fork 2: ", data);
	if (cpid2 == 0)
		ex_2;
	close(p_fd[0]);
	close(p_fd[1]);
	waitpid(cpid1, NULL, 0);
	waitpid(cpid2, NULL, 0);
}
