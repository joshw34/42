/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:47:38 by jwhitley          #+#    #+#             */
/*   Updated: 2024/02/18 10:48:23 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y);

void	ft_writeline(int x, char first, char mid, char last);

void	rush(int x, int y)
{
	int	line;

	line = 1;
	if (x > 0 && y > 0)
	{
		while (line <= y)
		{
			if (line == 1 || line == y)
				ft_writeline(x, 'o', '-', 'o');
			else
				ft_writeline(x, '|', ' ', '|');
			line++;
		}
	}
}

void	ft_writeline(int x, char first, char mid, char last)
{
	int	letter;

	letter = 1;
	while (letter <= x)
	{
		if (letter == 1)
			ft_putchar(first);
		else if (letter == x)
			ft_putchar(last);
		else
			ft_putchar(mid);
		letter++;
	}
	ft_putchar('\n');
}
