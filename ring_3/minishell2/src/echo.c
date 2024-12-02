#include "../inc/minishell.h"

void	echo_cmd(t_data *data)
{
	if (ft_strncmp(data->tokens->next->word, "-n", 3) == 0)
		printf("%s", data->tokens->next->next->word);
	else
		printf("%s\n", data->tokens->next->word);
}
