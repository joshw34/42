/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:17:40 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/14 15:18:05 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		num1;
	int		num2;
	char	operator;
	
	if (argc == 4)
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[3]);
		operator = argv[2][0];
		if (operator == '+')
			printf("%d", num1 + num2);
		else if (operator == '-')
			printf("%d", num1 - num2);
		else if (operator == '*')
			printf("%d", num1 * num2);
		else if (operator == '/')
			printf("%d", num1 / num2);
		else if (operator == '%')
			printf("%d", num1 % num2);
	}
	printf("\n");
	return (0);
}
