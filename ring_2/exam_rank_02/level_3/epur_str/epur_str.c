/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:47:06 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/31 16:26:33 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	int	last_char(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
		i--;
	return (i);
}

static	int	skip_spaces(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

static	void	epur_str(char *str)
{
	int	i;
	int	last;

	i = skip_spaces(str, 0);
	last = last_char(str) - 1;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			i = skip_spaces(str, i) - 1;
			if (i < last)
				write(1, " ", 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
