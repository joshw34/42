/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:14:18 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/22 16:32:31 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

static	void	last_word(char *s)
{
	int	len;
	int	start;
	int	end;

	len = ft_strlen(s) - 1;
	while (len >= 0 && (s[len] == ' ' || s[len] == '\t'))
		len--;
	end = len;
	while (len >= 0 && (s[len] != ' ' && s[len] != '\t'))
		len--;
	start = len + 1;
	while (start <= end)
	{
		write(1, &s[start], 1);
		start++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
