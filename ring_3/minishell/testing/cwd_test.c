#include "../inc/minishell.h"

int main(void)
{
	char *prompt;
	char *buffer;

	buffer = malloc(sizeof(char) * 201);
	buffer = getcwd(buffer, 200);
	prompt = ft_strjoin(ft_strrchr(buffer, '/') + 1, ": ");
	printf("%s\n", prompt);
	free(buffer);
	//free(prompt);
	return (0);
}

