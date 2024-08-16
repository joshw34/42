/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:45:01 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/16 16:11:47 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*temp;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	temp = str;
	while (j >= 0)
	{
		str[j] = temp[i];
		i++;
		j--;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original:  %s\n", argv[1]);
	printf("ft_strrev: %s\n", ft_strrev(argv[1]));
	return (0);
}