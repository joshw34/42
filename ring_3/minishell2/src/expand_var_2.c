#include "../inc/minishell.h"

void	remove_fake_var(t_tokens *token, int start, int end)
{
	char	*part_1;
	char	*part_2;
	char	*new;

	part_1 = ft_calloc(start + 1, sizeof(char));
	ft_strlcpy(part_1, token->word, start);
	part_2 = ft_strdup(token->word + end);
	new = ft_strjoin(part_1, part_2);
	free(token->word);
	token->word = new;
	free(part_1);
	free(part_2);
}