/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tovetouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:30:01 by tovetouc          #+#    #+#             */
/*   Updated: 2024/03/03 18:30:05 by tovetouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(char *str);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	units(char **num_arr, char **name_arr, char *nb, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		if (ft_strlen(num_arr[i]) == 1 && num_arr[i][0] == nb[0])
			print_num(name_arr[i]);
		i++;
	}
}

void	tens(char **num_arr, char **name_arr, char *nb, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		if (ft_strlen(num_arr[i]) == 2 && num_arr[i][0] == nb[0])
		{
			print_num(name_arr[i]);
		}
		i++;
	}
}

void	find_name(char **num_arr, char **name_arr, char *nb, int lines)
{
	int	length;

	length = ft_strlen(nb);
	if (length == 1)
		units(num_arr, name_arr, nb, lines);
	if (length == 2)
		tens(num_arr, name_arr, nb, length);
}
