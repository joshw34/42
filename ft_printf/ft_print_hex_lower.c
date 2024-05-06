#include "ft_printf.h"

static	size_t	find_len

void	ft_print_hex_lower(unsigned long num, size_t *char_count)
{
	//char	hex_low[] = "0123456789abcdef";
	
	/*while (num > 0)
	{
		ft_print_char(hex_low[num % 16], char_count);
		num /= 16;
	}*/
	(void)char_count;
	printf("num %ld\n", num);
	size_t	len = find_len(num);
	printf("strlen %ld", len);
}