#include "libft.h"

int main(void)
{
	size_t	i;
	char	str[] = "Hello, World";

	i = 0;
	while (i < ft_strlen(str))
	{
		write(1, &str[i], 1);
		i++;
	}
	return 0;
}
