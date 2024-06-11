#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (*str != '\0')
	{
		while (to_find[i] != '\0' && str[i] == to_find[i])
			i++;
		if (to_find[i] == '\0')
		{
			return (str);
		}
		str++;
	}
	return (0);
}

int main(void)
{
	char *haystack = "hello boby";
	char *needle = "";
	
	ft_strstr(haystack, needle);
	printf("%s", ft_strstr(haystack, needle));
	return (0);
	
}
