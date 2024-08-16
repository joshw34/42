/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:23:27 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/16 15:42:34 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include <stddef.h>

int	cmp_chars(const char c, const char *accept)
{
	int	i;

	i = 0;
	while (accept[i])
	{
		if (accept[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (cmp_chars(s1[i], s2) == 1)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("String: %s\nAccept: %s\n", argv[1], argv[2]);
	printf("ft_strpbrk: %s\n", ft_strpbrk(argv[1], argv[2]));
	printf("lc_strpbrk: %s\n", strpbrk(argv[1], argv[2]));
	return (0);
}*/
