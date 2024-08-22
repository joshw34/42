/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:36:19 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/22 17:58:40 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max;

	i = 1;
	if (!tab || len == 0)
		return (0);
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

/*int	main(int argc, char **argv)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc((argc - 1) * sizeof(int));
	while (i < argc - 1)
	{
		tab[i] = atoi(argv[i + 1]);
		i++;
	}
	printf("%d\n", max(tab, argc -1));
	free(tab);
	return (0);
}*/
