/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_process_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:15:07 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/20 15:48:16 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	int	get_var_end(t_tokens *temp, int i)
{
	int		j;
	char	*var_name;
	char	*exit_code;

	j = 1;
	var_name = ft_calloc(ft_strlen(temp->word) + 1, sizeof(char));
	var_name[0] = temp->word[i];
	i++;
	if (var_name[0] == '?')
	{
		temp->end = i - 1;
		exit_code = ft_itoa(g_last_signal);
		return (hd_var_insert(temp, exit_code, var_name));
	}
	while (temp->word[i] == '_' || ft_isalnum(temp->word[i]) == 1)
	{
		if (var_name[0] >= 48 && var_name[0] <= 57)
			break ;
		var_name[j] = temp->word[i];
		i++;
		j++;
	}
	temp->end = i - 1;
	return (hd_var_insert(temp, get_var(temp->data->env, var_name), var_name));
}

static	void	expand_hd_vars(t_tokens *temp)
{
	int	i;
	
	i = temp->start;
	while (temp->word[i])
	{
		if (temp->word[i] == '$')
		{
			while (temp->word[i] != '$')
				i++;
			if (temp->word[i + 1] && (temp->word[i + 1] == '?' || ft_isalnum(temp->word[i + 1]) == 1 || temp->word[i + 1] == '_'))
			{
				temp->start = i;
				i = get_var_end(temp, i + 1);
				continue ;
			}
		}
		i++;
	}
}

static	char	*expand_line(t_data *data, char *line)
{
	t_tokens	*temp;
	char		*processed_line;

	temp = token_lstnew(data, ft_strdup(line), NULL);
	temp->start = 0;
	temp->end = ft_strlen(line) - 1;
	expand_hd_vars(temp);
	processed_line = ft_strjoin(temp->word, "\n");
	token_lstclear(temp);
	return (processed_line);
}

bool	process_heredoc(t_data *data, char *delimiter)
{
	int		fd;
	char	*line;
	char	*processed;

	if (access(HERE_DOC_PATH, F_OK))
		unlink(HERE_DOC_PATH);
	fd = open(HERE_DOC_PATH, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd == -1)
		return (printf("Minishell: Error opening heredoc"), false);
	while (1)
	{
		line = readline("heredoc> ");
		if (!line || (ft_strlen(line) == ft_strlen(delimiter) && ft_strncmp(line, delimiter, (ft_strlen(delimiter))) == 0))
		{
			free(line);
			break ;
		}
		processed = expand_line(data, line);
		write(fd, processed, ft_strlen(processed));
		multi_free(2, line, processed);
	}
	close(fd);
	return (true);
}
