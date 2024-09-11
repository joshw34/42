/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshw <joshw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:03:23 by joshw             #+#    #+#             */
/*   Updated: 2024/09/11 14:15:14 by joshw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static	int	calculate_len(int start, int end)
{
	int	len;

	if (start < end)
		len = (end - start) + 1;
	else
		len = (start - end) + 1;
	return (len);
}

int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*result;

	i = 0;
	len = calculate_len(start, end);
	result = malloc(sizeof(int) * len);
	if (!result)
		return (NULL);
	while (i < len)
	{
		if (start < end)
		{
			result[i] = start;
			i++;
			start++;
		}
		else
		{
			result[i] = start;
			i++;
			start--;
		}
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int	*result;
	int	i;
	int	start;
	int	end;
	int	len;

	(void)argc;
	start = atoi(argv[1]);
	end = atoi(argv[2]);
	len = abs(start - end) + 1;
	result = ft_range(start, end);
	i = 0;
	while (i < len)
	{
		printf("%d\n", result[i]);
		i++;
	}
	return (0);
}
