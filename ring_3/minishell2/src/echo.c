/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:33:47 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/04 15:33:48 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	echo_cmd(t_data *data)
{
	if (ft_strncmp(data->tokens->next->word, "-n", 3) == 0)
		printf("%s", data->tokens->next->next->word);
	else
		printf("%s\n", data->tokens->next->word);
}
