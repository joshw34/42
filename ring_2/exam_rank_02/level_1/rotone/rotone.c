/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:40:10 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/13 16:55:13 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rotone(char c)
{
	char	new;

	if (c == 'Z')
		new = 'A';
	else if (c == 'z')
		new = 'a';
	else
		new = c + 1;
	write(1, &new, 1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			c = argv[1][i];
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
				rotone(c);
			else
				write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
