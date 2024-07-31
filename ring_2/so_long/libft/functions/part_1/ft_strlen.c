/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:18:10 by jwhitley          #+#    #+#             */
/*   Updated: 2024/07/31 15:29:29 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if(str == NULL)
		return (i);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
