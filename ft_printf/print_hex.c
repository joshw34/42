#include "ft_printf.h"

static	size_t	ft_find_len(unsigned long num)
{
	size_t	i;

	i = 0;
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

void	ft_print_hex_upper(unsigned long num, size_t *char_count)
{
	char	hex_upp[] = "0123456789ABCDEF";
	char	*rev;
	size_t	len;
	size_t	i;

	len = ft_find_len(num);
	i = len - 1;
	rev = ft_calloc(len + 1, sizeof(char));
	if (rev == NULL)
		return;
	while(num > 0)
	{
		rev[i] = hex_upp[num % 16];
		num /= 16;
		i--;
	}
	ft_print_str(rev, char_count);
	free(rev);
}

void	ft_print_hex_lower(unsigned long num, size_t *char_count)
{
	char	hex_low[] = "0123456789abcdef";
	char	*rev;
	size_t	len;
	size_t	i;

	len = ft_find_len(num);
	i = len - 1;
	rev = ft_calloc(len + 1, sizeof(char));
	if (rev == NULL)
		return;
	while(num > 0)
	{
		rev[i] = hex_low[num % 16];
		num /= 16;
		i--;
	}
	ft_print_str(rev, char_count);
	free(rev);
}
