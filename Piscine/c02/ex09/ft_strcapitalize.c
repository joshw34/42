/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:46:39 by jwhitley          #+#    #+#             */
/*   Updated: 2024/03/04 10:57:16 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		if (str[i] > 96 && str[i] < 123)
		{
			if (!(str[i - 1] > 47 && str[i - 1] < 58))
			{
				if (!(str[i - 1] > 96) && str[i - 1] < 123)
				{
					if (!(str[i - 1] > 64 && str[i - 1] < 91))
					{
						str[i] = str[i] - 32;
					}
				}
			}
		}
		i++;
	}
	return (str);
}
