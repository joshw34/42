/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:34:44 by jwhitley          #+#    #+#             */
/*   Updated: 2024/02/14 15:41:32 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	pos;
	char	neg;

	pos = 'P';
	neg = 'N';
	if (n < 0)
	{
		write(1, &neg, 1);
	}
	else
		write(1, &pos, 1);
}
