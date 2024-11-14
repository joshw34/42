#include "../inc/minishell.h"
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void	print_result(int out_fd)
{
	char *line;
	//while (get_next_line(out_fd))
	line = get_next_line(out_fd);
	printf("%s\n", line);
}

void	run_command(char *str, char **env, int out_fd)
{
	char **args = ft_split(str, ' ');	
	char *path = ft_strjoin("/usr/bin/", args[0]);
	pid_t pid = fork();
	dup2(out_fd, STDOUT_FILENO);
	execve(path, args, env);
	waitpid(pid, NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	char	*input;

	(void)ac;
	(void)av;
	while (1)
	{
		input = readline("Enter text here: ");
		if (ft_strncmp(input, "END", 4) == 0)
		{
			rl_clear_history();
			free(input);
			return (0);
		}
		if (input != NULL)
		{
			//int in_fd = open("infile", O_RDONLY);
			int out_fd = open("outfile", O_RDWR);
			run_command(input, env, out_fd);
			print_result(out_fd);
			add_history(input);
			free(input);
		}
	}
	return (0);
}
