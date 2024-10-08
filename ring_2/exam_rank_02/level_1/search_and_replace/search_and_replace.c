/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:58:13 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/14 12:16:39 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	search_and_replace(char **s)
{
	int	i;

	i = 0;
	while (s[0][i] != '\0')
	{
		if (s[0][i] == s[1][0])
			s[0][i] = s[2][0];
		write(1, &s[0][i], 1);
		i++;
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
	if (argc == 4 && ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
		search_and_replace(argv + 1);			
	write(1, "\n", 1);
	return (0);
}