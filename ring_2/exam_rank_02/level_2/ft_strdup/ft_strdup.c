/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:52:58 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/16 15:11:22 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	result = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*int	main(int argc, char **argv)
{
	char	*new_string;

	(void)argc;
	new_string = ft_strdup(argv[1]);
	printf("Original : %s\n", argv[1]);
	printf("ft_strdup: %s\n", argv[1]);
	free(new_string);
	return (0);
}*/
