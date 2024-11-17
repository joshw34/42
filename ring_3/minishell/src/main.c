#include "../inc/minishell.h"

void	run_command(char *str, char **env)
{
	char **args = ft_split(str, ' ');
	char *path = ft_strjoin("/usr/bin/", args[0]);
	pid_t pid = fork();
	if (pid == 0)
		execve(path, args, env);
	else
		waitpid(pid, NULL, 0);
	free(path);
	free_array(args);
}

int	main(int ac, char **av, char **env)
{
	char	*input;

	(void)ac;
	(void)av;
	char	*prompt;
	while (1)
	{
		prompt = get_prompt();
		input = readline(prompt);
		if (ft_strncmp(input, "exit", 4) == 0)
		{
			rl_clear_history();
			free(prompt);
			free(input);
			exit(EXIT_SUCCESS);
		}
		if (input != NULL)
		{
			run_command(input, env);
			add_history(input);
			free(prompt);
			free(input);
		}
	}
	return (0);
}
