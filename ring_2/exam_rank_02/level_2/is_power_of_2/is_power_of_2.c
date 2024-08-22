/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:34:14 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/22 16:12:24 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	if ((n & (n - 1)) == 0)
		return (1);
	else
		return (0);
}

/*int	main(int argc, char **argv)
{
	int	num;
	int	result;

	(void)argc;
	num = atoi(argv[1]);
	result = is_power_of_2(num);
	if (result == 1)
		printf("%d is a power of 2\n", num);
	else if (result == 0)
		printf("%d is not a power of 2\n", num);
	return (0);
}*/
