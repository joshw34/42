/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:38:53 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/22 14:53:09 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include <stddef.h>

static	int	comp_chars(const char c, const char *accept)
{
	int	i;

	i = 0;
	while (accept[i])
	{
		if (c == accept[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (comp_chars(s[i], accept) == 0)
			return (i);
		i++;
	}
	return (i);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("String: %s\tAccept: %s\n", argv[1], argv[2]);
	printf("ft_strspn: %ld\n", ft_strspn(argv[1], argv[2]));
	printf("lc_strspn: %ld\n", strspn(argv[1], argv[2]));
	return (0);
}*/
