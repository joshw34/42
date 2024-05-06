#include "ft_printf.h"

void	ft_print_str(char *str, size_t *char_count)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		ft_print_char(str[i], char_count);
		i++;
	}
}