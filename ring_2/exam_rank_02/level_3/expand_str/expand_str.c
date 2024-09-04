/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:45:17 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/04 22:26:54 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	expand_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t')
			write(1, "   ", 3);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);	
	return (0);
}