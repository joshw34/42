/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:00:20 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/04 16:05:39 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	add_var_start(t_tokens *tok, char *var, int end)
{
	char	*part_2;
	char	*new;

	part_2 = ft_strdup(tok->word + end);
	new = ft_strjoin(var, part_2);
	free(tok->word);
	tok->word = new;
	free(part_2);
}

static	void	add_var_end(t_tokens *tok, char *var, int start)
{
	char	*part_1;
	char	*new;

	part_1 = ft_calloc(start + 1, sizeof(char));
	ft_strlcpy(part_1, tok->word, start);
	new = ft_strjoin(part_1, var);
	free(tok->word);
	tok->word = new;
	free(part_1);
}

static	void	add_var_middle(t_tokens *token, char *var, int start, int end)
{
	char	*part_1;
	char	*part_2;
	char	*new_temp;
	char	*new_final;

	part_1 = ft_calloc(start + 1, sizeof(char));
	ft_strlcpy(part_1, token->word, start);
	part_2 = ft_strdup(token->word + end);
	new_temp = ft_strjoin(part_1, var);
	new_final = ft_strjoin(new_temp, part_2);
	free(token->word);
	token->word = new_final;
	free(part_1);
	free(part_2);
	free(new_temp);
}

static	void	var_swap(t_data *data, t_tokens *token, int start, int end)
{
	char	*temp;
	char	*var;

	temp = ft_strdup(token->word + start);
	temp[end - start] = '\0';
	var = ft_strdup(get_var(data->env, temp));
	if (var == NULL)
		return (free(temp));
	if (ft_strlen(token->word) == ft_strlen(temp) + 1)
	{
		free(token->word);
		token->word = ft_strdup(get_var(data->env, temp));
	}
	else if (start > 1 && (size_t)end < ft_strlen(token->word))
		add_var_middle(token, var, start, end);
	else if (start > 1)
		add_var_end(token, var, start);
	else if ((size_t)end < ft_strlen(token->word))
		add_var_start(token, var, end);
	free(var);
	free(temp);
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
		var_swap(data, token, start, end);
}
