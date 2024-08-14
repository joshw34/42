/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:52:12 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/14 14:13:32 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	camel_to_snake(char *camel)
{
	int		i;

	i = 0;
	while (camel[i])
	{
		if (camel[i] >= 'A' && camel[i] <= 'Z')
		{
			camel[i] = camel[i] + 32;
			write(1, "_", 1);
			write(1, &camel[i], 1);
		}
		else
			write(1, &camel[i], 1);
		i++;
	}
	
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		camel_to_snake(argv[1]);
	write(1, "\n", 1);
	return (0);
}
