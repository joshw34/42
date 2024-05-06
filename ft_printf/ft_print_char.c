#include "ft_printf.h"

void	ft_print_char(char c, size_t *char_count)
{
	write(1, &c, 1);
	*char_count += 1;
}