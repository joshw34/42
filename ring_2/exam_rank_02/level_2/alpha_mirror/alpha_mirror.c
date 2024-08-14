/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:47:53 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/14 13:20:28 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	alpha_mirror(char c)
{
	if ((c >= 'a' && c <= 'z'))
	{
		if (c <= 'm')
			c = 'z' - (c - 'a');
		else
			c = 'a' + ('z' - c);
	}
	else if ((c >= 'A' && c <= 'Z'))
	{
		if (c <= 'M')
			c = 'Z' - (c - 'A');
		else
			c = 'A' + ('Z' - c);
	}
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;	
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			alpha_mirror(argv[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}