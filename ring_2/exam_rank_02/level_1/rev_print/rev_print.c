/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:26:00 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/13 16:04:00 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rev_print(char *str, int i)
{
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = ft_strlen(argv[1]) - 1;
		rev_print(argv[1], i);
	}
	write(1, "\n", 1);
}
