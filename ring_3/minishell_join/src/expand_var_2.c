/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:03:40 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/08 16:17:09 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
