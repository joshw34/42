/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:49:42 by jwhitley          #+#    #+#             */
/*   Updated: 2024/02/20 13:49:44 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (*str != '\0')
	{
		while (to_find[i] != '\0' && str[i] == to_find[i])
			i++;
		if (to_find[i] == '\0')
		{
			return (str);
		}
		str++;
	}
	return (0);
}
