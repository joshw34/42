#include "../inc/minishell.h"

char	*get_prompt(void)
{
	char	*prompt;
	char	*buffer;

	buffer = malloc(sizeof(char) * 201);
	buffer = getcwd(buffer, 200);
	prompt = ft_strjoin(ft_strrchr(buffer, '/') + 1, ": ");
	free(buffer);
	return (prompt);
}

void	free_array(char **array)
{
	int	i;
	
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
