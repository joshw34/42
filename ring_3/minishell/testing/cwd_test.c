/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwd_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:37:23 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/17 16:38:35 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(void)
{
	char	*prompt;
	char	*buffer;

	buffer = malloc(sizeof(char) * 201);
	buffer = getcwd(buffer, 200);
	prompt = ft_strjoin(ft_strrchr(buffer, '/') + 1, ": ");
	printf("%s\n", prompt);
	free(buffer);
	free(prompt);
	return (0);
}
