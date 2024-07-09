/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:19:48 by jwhitley          #+#    #+#             */
/*   Updated: 2024/07/09 19:26:32 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

static	void	ft_print_char(char c, size_t *char_count)
{
	write(2, &c, 1);
	*char_count += 1;
}

static	void	ft_print_str(char *str, size_t *char_count)
{
	size_t	len;
	size_t	i;

	if (str == NULL)
	{
		ft_print_str("(null)", char_count);
		return ;
	}
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		ft_print_char(str[i], char_count);
		i++;
	}
}

static	void	ft_format_type(va_list args, char *str, size_t *char_count)
{
	if (*str == 'c')
		ft_print_char(va_arg(args, int), char_count);
	else if (*str == 's')
		ft_print_str(va_arg(args, char *), char_count);
}

int	error_print(const char *str, ...)
{
	size_t	char_count;

	char_count = 0;
	va_list(args);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *str + 1)
		{
			str++;
			ft_format_type(args, (char *)str, &char_count);
		}
		else
			ft_print_char(*str, &char_count);
		str++;
	}
	va_end(args);
	return (char_count);
}
