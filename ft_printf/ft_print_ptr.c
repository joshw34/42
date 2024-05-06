#include "ft_printf.h"

ft_print_ptr(void *ptr, size_t *char_count)
{
	unsigned long	addr;

	addr = (unsigned long) ptr;
	ft_print_str("0x", char_count);
	ft_print_hex_lower(addr, char_count);
}