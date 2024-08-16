/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:32:24 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/16 14:50:53 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include <stddef.h>

size_t	cmp_chars(const char c, const char *reject)
{
	size_t	i;

	i = 0;
	while (reject[i])
	{
		if (reject[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	result;
	size_t	i;

	result = 0;
	i = 0;
	while (s[i])
	{
		if (cmp_chars(s[i], reject) == 0)
			result++;
		else
			break ;
		i++;
	}
	return (result);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("String: %s\nReject: %s\n", argv[1], argv[2]);
	printf("%lu\n", ft_strcspn(argv[1], argv[2]));
	printf("%lu\n", strcspn(argv[1], argv[2]));
	return (0);
}*/
