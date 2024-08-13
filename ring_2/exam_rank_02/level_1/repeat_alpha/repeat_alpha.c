/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:07:23 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/13 15:24:39 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_chars(char c)
{
	int	alpha_index;

	if (c >= 'a' && c <= 'z')
		alpha_index = c - 96;
	else if (c >= 'A' && c <= 'Z')
		alpha_index = c - 64;
	else
		alpha_index = 1;
	while (alpha_index > 0)
	{
		write(1, &c, 1);
		alpha_index--;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			print_chars(argv[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
}
