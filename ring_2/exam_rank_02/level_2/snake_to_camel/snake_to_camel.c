/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:11:51 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/31 12:45:25 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include <unistd.h>

static	int	find_first_letter(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '_')
		i++;
	return (i);
}

static	void	snake_to_camel(char *str)
{
	int	i;

	i = find_first_letter(str);
	while (str[i])
	{
		while (str[i] == '_')
		{
			i++;
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		snake_to_camel(argv[1]);
	write(1, "\n", 1);
	return (0);
}
