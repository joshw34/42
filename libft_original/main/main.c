#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

// ft_atoi

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("ft_atoi: %d\n", ft_atoi(argv[1]));
	printf("atoi:    %d\n", atoi(argv[1]));
	return (0);
}*/


// ft_bzero

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("Before: %s\n", argv[1]);
	ft_bzero(argv[1], 8 * sizeof(char));
	printf("After:  %s\n", argv[1]);
	return (0);
}*/


// ft_calloc

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("Return: %p", ft_calloc(atoi(argv[1]), atoi(argv[2])));
	return (0);
}*/


// ft_isalnum

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_isalnum(argv[1][0]));
	printf("%d\n", isalnum(argv[1][0]));
	return (0);
}*/


// ft_isalpha

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_isalpha(argv[1][0]));
	printf("%d\n", isalpha(argv[1][0]));
	return (0);
}*/


// ft_isascii

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_isascii(argv[1][0]));
	printf("%d\n", isascii(argv[1][0]));
	return (0);
}*/


// ft_isdigit

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_isdigit(argv[1][0]));
	printf("%d\n", isdigit(argv[1][0]));
	return (0);
}*/


// ft_isprint

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_isprint(argv[1][0]));
	printf("%d\n", isprint(argv[1][0]));
	return (0);
}*/


// ft_memchr

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("s: %s\tc: %s\tn: %s\n", argv[1], argv[2], argv[3]);
	printf("Return: %p\n", ft_memchr(argv[1], argv[2][0], atoi(argv[3]) * sizeof(char)));
	printf("Return: %p\n", memchr(argv[1], argv[2][0], atoi(argv[3]) * sizeof(char)));
	return (0);
}*/


// ft_memcmp

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("s1: %s\ns2: %s\nsize: %s\n", argv[1], argv[2], argv[3]);
	printf("ft_memcmp: %d\n", ft_memcmp(argv[1], argv[2], atoi(argv[3])));
	printf("memcmp:    %d\n", memcmp(argv[1], argv[2], atoi(argv[3])));
	return (0);
}*/


// ft_memcpy

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("Before: %s\n", argv[1]);
	printf("Adress of dest[0]: %p\n", &argv[1][0]);
	printf("Returned Pointer:  %p\n", ft_memcpy(argv[1], argv[2], (atoi(argv[3]) * sizeof(char))));
	printf("After:  %s\n", argv[1]);
	return (0);
}*/


// ft_memmove

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("Before %s\n", argv[1]);
	printf("Ret. Pointer:       %p\n", ft_memmove(argv[1], argv[2], (atoi(argv[3]) * sizeof(char))));
	printf("Addr of argv[1][0]: %p\n", &argv[1][0]);
	printf("After: %s\n", argv[1]);
	return (0);
}*/


// ft_memset

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("Before: %s\n", argv[1]);
	//ft_memset(argv[1], 'x', 4*sizeof(char));
	printf("Return: %p\n", ft_memset(argv[1], argv[2][0], (atoi(argv[3]) * sizeof(char))));
	printf("After:  %s\n", argv[1]);
}*/


// ft_strchr

/*int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("String: %s\tTo Find: %c\n", argv[1], argv[2][0]);
	printf("Return: %s\n", ft_strchr(argv[1], argv[2][0]));
	printf("Return: %s\n", strchr(argv[1], argv[2][0]));
	printf("Return: %p\n", ft_strchr(argv[1], argv[2][0]));
	printf("Return: %p\n", strchr(argv[1], argv[2][0]));
	printf("\nString: %s\tTo Find: \\0\n", argv[1]);
	printf("Return: %s\n", ft_strchr(argv[1], '\0'));
	printf("Return: %s\n", strchr(argv[1], '\0'));
	printf("Return: %p\n", ft_strchr(argv[1], '\0'));
	printf("Return: %p\n", strchr(argv[1], '\0'));
	return (0);
}*/


// ft_strdup

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("Return: %s", ft_strdup(argv[1]));
	return (0);
}*/


// ft_strjoin

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("s1: %s\ns2: %s\n", argv[1], argv[2]);
	printf("Return: %s\n", ft_strjoin(argv[1], argv[2]));
	return (0);
}*/


// ft_strlcat

/*int	main(void)
{
	char	dest[] = "Hello";
	char	src[] = "Bonjour";
	size_t	size = 11;

printf("Before: %s\n", dest);
printf("Return: %lu\n", ft_strlcat(dest, src, size));
printf("After:  %s\n", dest);
return (0);
}*/


// ft_strlcpy

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("Before: %s\n", argv[1]);
	ft_strlcpy(argv[1], argv[2], (atoi(argv[3]) * sizeof(char)));
	//strlcpy(argv[1], argv[2], (atoi(argv[3]) * sizeof(char)));
	printf("After:  %s\n", argv[1]);
	printf("Return: %lu\n", ft_strlcpy(argv[1], argv[2], (atoi(argv[3]) * sizeof(char))));
	//printf("Return: %lu\n", strlcpy(argv[1], argv[2], (atoi(argv[3]) * sizeof(char))));
	return (0);
}*/


// ft_strlen

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("%lu\n", ft_strlen(argv[1]));
	printf("%lu\n", strlen(argv[1]));
	return (0);
}*/


// ft_strncmp

/*int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("String 1: %s\tString 2: %s\tn: %s\n", argv[1], argv[2], argv[3]);
	printf("ft_strncmp: %d\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	printf("c strncmp:  %d\n", strncmp(argv[1], argv[2], atoi(argv[3])));
	return (0);
}*/


// ft_strnstr

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("Big: %s\nLittle: %s\nlen: %s\n", argv[1], argv[2], argv[3]);
	printf("ft_strnstr: %s\n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
	return (0);
}*/


// ft_strrchr

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("String: %s\tTo Find: %c\n", argv[1], argv[2][0]);
	printf("Return: %s\n", ft_strrchr(argv[1], argv[2][0]));
	printf("Return: %s\n", strrchr(argv[1], argv[2][0]));
	printf("Return: %p\n", ft_strrchr(argv[1], argv[2][0]));
	printf("Return: %p\n", strrchr(argv[1], argv[2][0]));
	printf("\nString: %s\tTo Find: \\0\n", argv[1]);
	printf("Return: %s\n", ft_strrchr(argv[1], '\0'));
	printf("Return: %s\n", strrchr(argv[1], '\0'));
	printf("Return: %p\n", ft_strrchr(argv[1], '\0'));
	printf("Return: %p\n", strrchr(argv[1], '\0'));
	return (0);
}*/


// ft_strtrim

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("String: %s\nSet: %s\n", argv[1], argv[2]);
	printf("Return: %s\n", ft_strtrim(argv[1], argv[2]));
	return (0);
}*/


// ft_substr

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("String: %s\nIndex: %s\nlen: %s\n", argv[1], argv[2], argv[3]);
	printf("Return: %s\n", ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
	return (0);
}*/


// ft_tolower

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("Input:  %c\n", argv[1][0]);
	printf("Return: %c\n", ft_tolower(argv[1][0]));
	printf("Return: %c\n", ft_tolower(argv[1][0]));
	return (0);
}*/


//  ft_toupper

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("Input:  %c\n", argv[1][0]);
	printf("Return: %c\n", ft_toupper(argv[1][0]));
	printf("Return: %c\n", toupper(argv[1][0]));
	return (0);
}*/


// ft_split

/*int	main(int argc, char **argv)
{
	(void)argc;
	char	**ret;
	int		i;

	i = 0;
	ret = ft_split(argv[1], argv[2][0]);
	printf("s: %s\nc: %s\n", argv[1], argv[2]);
	while (ret[i])
	{
		printf("%p\t%s\n", ret[i], ret[i]);
		i++;
	}
	printf("%p\t%s\n", ret[i], ret[i]);
	return (0);
}*/


// ft_itoa

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("Input: 	%s\n", argv[1]);
	printf("Return: %s\n", ft_itoa(ft_atoi(argv[1])));
	return (0);
}*/


// ft_strmapi

/*char	change_alt_case(unsigned int i, char c)
{
	if (i % 2 == 0)
	{
		if (c >= 'a' && c <= 'z')
			return (ft_toupper(c));
	}
	else if (i % 2 != 0)
	{
		if (c >= 'A' && c <= 'Z')
			return(ft_tolower(c));
	}
	return (c);
}

int	main(int argc, char **argv)
{
	(void)argc;
	printf("Input:  %s\n", argv[1]);
	printf("Output: %s\n", ft_strmapi(argv[1], change_alt_case));
	return (0);
}*/


// ft_striteri

/*void	change_alt_case(unsigned int i, char *c)
{
	if (i % 2 == 0)
	{
		if (*c >= 'a' && *c <= 'z')
			*c = *c - 32;
	}
	if (i % 2 != 0)
	{
		if (*c >= 'A' && *c <= 'Z')
			*c = *c + 32;
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	printf("Before: %s\n", argv[1]);
	ft_striteri(argv[1], change_alt_case);
	printf("After:  %s\n", argv[1]);
	return (0);
}*/


// ft_putchar_fd

/*int	main(int argc, char **argv)
{
	(void)argc;
	int	fd;
	fd = open("test.txt", O_APPEND | O_RDWR);
	ft_putchar_fd(argv[1][0], fd);
	close(fd);
}*/


// ft_putstr_fd

/*int	main(int argc, char **argv)
{about:blank#blocked
	(void)argc;
	int	fd;
	fd = open("test.txt", O_APPEND | O_RDWR);
	ft_putstr_fd(argv[1], fd);
	close(fd);
}*/


// ft_putendl_fd

/*int	main(int argc, char **argv)
{
	(void)argc;
	int	fd;
	fd = open("test.txt", O_APPEND | O_RDWR);
	ft_putendl_fd(argv[1], fd);
	close(fd);
}*/


// ft_putnbr_fd

/*int	main(int argc, char **argv)
{
	(void)argc;
	int	fd;
	fd = open("test.txt", O_APPEND | O_RDWR);
	ft_putnbr_fd(ft_atoi(argv[1]), fd);
	close(fd);
}*/
