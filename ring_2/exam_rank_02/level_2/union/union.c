/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:04:45 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/31 14:07:54 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	void	check_char(char *str, int seen[256])
{
	int	i;

	i = 0;	
	while (str[i])
	{
		if (seen[(unsigned char)str[i]] == 0)
		{
			write(1, &str[i], 1);
			seen[(unsigned char)str[i]] = 1;
		}
		i++;
	}
}

static	void	print_union(char *s1, char *s2)
{
	int		i;
	int	seen[256];

	i = 0;
	while (i < 256)
	{
		seen[i] = 0;
		i++;
	}
	check_char(s1, seen);
	check_char(s2, seen);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		print_union(argv[1], argv[2]);
	write(1, "\n", 1);
}
