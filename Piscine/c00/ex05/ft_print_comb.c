/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:20:07 by jwhitley          #+#    #+#             */
/*   Updated: 2024/02/29 10:03:26 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	h;
	char	t;
	char	u;

	h = '0';
	while (h <= '7')
	{
		t = h + 1;
		while (t <= '8')
		{
			u = t + 1;
			while (u <= '9')
			{
				write(1, &h, 1);
				write(1, &t, 1);
				write(1, &u, 1);
				if (h != '7')
					write(1, ", ", 2);
				u++;
			}
			t++;
		}
		h++;
	}
}

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
