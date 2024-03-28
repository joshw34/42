/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tovetouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:27:25 by tovetouc          #+#    #+#             */
/*   Updated: 2024/03/03 18:42:18 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*parse(void);
char	**create_num_array(char *dict_str);
char	**create_name_array(char *dict_str);
int		count_lines(char *str);
void	find_name(char **num_arr, char **name_arr_arr, char *nb, int lines);

void	free_arrays(char **array, int lines)
{
	int	n;

	n = 0;
	while (n < lines)
	{
		free(array[n]);
		n++;
	}
	free(array);
}

void	error_msg(void)
{
	write(1, "Error", 5);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	char	*dict_str;
	char	**num_arr;
	char	**name_arr;
	int		lines;

	dict_str = parse();
	lines = count_lines(dict_str);
	if (argc == 1 || argc > 3)
		error_msg();
	if (argc == 2 && argv[1][0] == '-')
		error_msg();
	if (argc == 3 && argv[2][0] == '-')
		error_msg();
	num_arr = create_num_array(dict_str);
	name_arr = create_name_array(dict_str);
	free(dict_str);
	find_name(num_arr, name_arr, argv[1], lines);
	free_arrays(num_arr, lines);
	free_arrays(name_arr, lines);
	return (0);
}
