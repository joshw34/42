#include "ft_printf.h"

void	ft_print_ptr(void *ptr, size_t *char_count)
{
	unsigned long	addr;

	addr = (unsigned long) ptr;
	if (addr == 0)
	{
		ft_print_str("(nil)", char_count);
		return;
	}
	ft_print_str("0x", char_count);
	ft_print_hex_lower(addr, char_count);
}