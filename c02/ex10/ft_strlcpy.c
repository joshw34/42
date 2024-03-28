/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:18:24 by jwhitley          #+#    #+#             */
/*   Updated: 2024/03/04 12:49:23 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size < 1)
		return (0);
	while (i < (size - 1) && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
