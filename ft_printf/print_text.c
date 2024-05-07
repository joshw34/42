#include "ft_printf.h"

void	ft_print_char(char c, size_t *char_count)
{
	write(1, &c, 1);
	*char_count += 1;
}

void	ft_print_str(char *str, size_t *char_count)
{
	size_t	len;
	size_t	i;

	if (str == NULL)
	{
		ft_print_str("(null)", char_count);
		return;
	}
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		ft_print_char(str[i], char_count);
		i++;
	}
}
