#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"


# include <stdio.h>

int		ft_printf(const char *, ...);
void	ft_format_type(va_list args, char *str, size_t *char_count);
void	ft_print_char(char c, size_t *char_count);
void	ft_print_str(char *str, size_t *char_count);
void	ft_print_ptr(void *ptr, size_t *char_count);
void	ft_print_hex_lower(unsigned long num, size_t *char_count);
void	ft_print_hex_upper(unsigned long num, size_t *char_count);
void	ft_print_int(int num, size_t *char_count);
void	ft_print_uint(unsigned int num, size_t *char_count);

#endif