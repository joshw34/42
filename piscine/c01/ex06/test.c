/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:16:12 by jwhitley          #+#    #+#             */
/*   Updated: 2024/02/15 19:58:15 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	char	*str;

	str = "abcdefghijklmnopqrstuvwxyz";
	ft_strlen(str);
	return (0);
}

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (*str != '\0')
	{
		str++;
		l++;
	}
	printf("%d", l);
	return (l);
}
