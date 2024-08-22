/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:54:32 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/22 15:28:37 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	int	check_double(char *s1, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (s1[i] == s1[index])
			return (0);
		i++;
	}
	return (1);
}

static	int	check_char(char c, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (c == s2[i])
			return (1);
		i++;
	}
	return (0);
}

static	void	inter(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (check_double(s1, i) == 1 && check_char(s1[i], s2) == 1)
			write(1, &s1[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
