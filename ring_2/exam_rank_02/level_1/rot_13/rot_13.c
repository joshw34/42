/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:05:20 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/13 16:33:42 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rot_13(char c)
{
	char	new;

	if (c <= 90)
	{
		if (c > 'M')
			new = c - 13;
		else
			new = c + 13;
	}
	else if (c <= 122)
	{
		if (c > 'm')
			new = c - 13;
		else
			new = c + 13;
	}
	write(1, &new, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if ((argv[1][i] >= 'a' && argv[1][i] <= 'z')
				|| (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
				rot_13(argv[1][i]);
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
