/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:09:02 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/16 14:30:26 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("S1: %s\nS2: %s\n", argv[1], argv[2]);
	printf("ft_strcmp: %d\n", ft_strcmp(argv[1], argv[2]));
	printf("lc_strcmp: %d\n", strcmp(argv[1], argv[2]));
	return (0);
}*/
