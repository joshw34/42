/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:00:20 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/03 15:33:59 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	simple_swap(t_data *data, t_tokens *token, char *temp)
{
	free(token->word);
	token->word = ft_strdup(get_var(data->env, temp));
}

static	void	replace_var_string(t_data *data, t_tokens *token, int start, int end)
{
	char *temp;

	temp = ft_strdup(token->word + start);
	temp[end - start] = '\0';
	if (get_var(data->env, temp) == NULL)
		return ;
	if (ft_strlen(token->word) == ft_strlen(temp) + 1)
		printf("swap\n");
}

void	expand_var(t_data *data, t_tokens *token)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	start = -1;
	end = -1;
	while (token->word[i])
	{
		if (token->word[i] == '$')
		{
			i++;
			start = i;
			while (ft_isalnum(token->word[i]) == 1 || token->word[i] == '_')
				i++;
			end = i;
			break ;
		}
		i++;
	}
	if (start > 0 && end > start)
		replace_var_string(data, token, start, end);
}
