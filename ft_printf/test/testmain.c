#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "../ft_printf.h"

#define GREEN_TEXT "\033[0;32m"
#define RED_TEXT "\033[0;31m"
#define BLUE_TEXT "\033[0;34m"
#define RESET_TEXT "\033[0m"

char *copy_txt_to_string(const char *test_result)
{
	// Open the text file
	FILE *file = fopen(test_result, "r");
	if (file == NULL)
	{
		printf("Error opening text file");
		return (NULL);
	}

	// Find text file size
	fseek(file, 0, SEEK_END);
	size_t file_size = ftell(file);
	rewind(file);

	// Allocate memory for string
	char *file_content = calloc(file_size + 1, sizeof(char));
	if (file_content == NULL)
	{
		printf("Error allocating memory");
		fclose(file);
		return (NULL);
	}

	// Copy text file contents to string
	size_t bytes_read = fread(file_content, 1, file_size, file);
	if (bytes_read != file_size)
	{
		printf("Error reading file");
		free(file_content);
		fclose(file);
		return (NULL);
	}

	// Close the file and return the string
	fclose(file);
	return (file_content);
}

void check_return(int me, int lc)
{
	//printf("Return Value(me): %d\t", me);
	//printf("Return Value(lc): %d\n", lc);
	if (me == lc)
		printf(GREEN_TEXT "Return Value OK\n" RESET_TEXT);
	else
	{
		printf(RED_TEXT "Return Value KO\n" RESET_TEXT);
		printf("Return Value(me): %d\t", me);
		printf("Return Value(lc): %d\n", lc);
	}
}

void compare_files(int test_num)
{
	const char *my_output = copy_txt_to_string("my_output.txt");
	const char *lc_output = copy_txt_to_string("libc_output.txt");

	//printf("Output(me): %s\n", my_output);
	//printf("Output(lc): %s\n", lc_output);
	if (my_output == NULL || lc_output == NULL)
	{
		printf("Test %d: Error reading files", test_num);
		return;
	}
	else if (strcmp(my_output, lc_output) == 0)
		printf(GREEN_TEXT "Output OK\n" RESET_TEXT, test_num);
	else
	{
		printf(RED_TEXT "Output KO\n" RESET_TEXT, test_num);
		printf("Output(me): %s\n", my_output);
		printf("Output(lc): %s\n", lc_output);
	}
}

void	mix_test(void)
{
	printf(BLUE_TEXT "\n*********\nMix Tests\n*********\n" RESET_TEXT);

	int stdout_copy = dup(STDOUT_FILENO);
	int test_num = 0;
	int my_fd;
	int lc_fd;
	int my_return;
	int lc_return;

	// Test 1
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\"%%%%%%c%%%%%%s%%%%%%d%%%%%%i%%%%%%u%%%%%%x%%%%%%X%%%%%%%% %%%%%%c%%%%%%s%%%%%%d%%%%%%i%%%%%%u%%%%%%x%%%%%%X%%%%%%%% %%%%%%c%%%%%%s%%%%%%d%%%%%%i%%%%%%u%%%%%%x%%%%%%X%%%%%%%% %%c%%%%\", 'A', \"42\", 42, 42 ,42 , 42, 42, 'B', \"-42\", -42, -42 ,-42 ,-42, 42, 'C', \"0\", 0, 0 ,0 ,0, 42, 0)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);
}

void	percent_test(void)
{
	printf(BLUE_TEXT "\n********\n%%%% Tests\n********\n" RESET_TEXT);

	int stdout_copy = dup(STDOUT_FILENO);
	int test_num = 0;
	int my_fd;
	int lc_fd;
	int my_return;
	int lc_return;

	// Test 1
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%%% \")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %% ");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %% ");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 2
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%%%%%%% \")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %%%% ");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %%%% ");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 3
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%%% %%%% %%%% \")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %% %% %% ");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %% %% %% ");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 4
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%%%  %%%%  %%%% \")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %%  %%  %% ");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %%  %%  %% ");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 5
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%%%   %%%%   %%%% \")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %%   %%   %% ");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %%   %%   %% ");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 6
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\"%%%%\")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf("%%");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf("%%");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 7
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\"%%%% %%%%\")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf("%% %%");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf("%% %%");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);
}

void X_test(void)
{
	printf(BLUE_TEXT "\n********\n%%X Tests\n********\n" RESET_TEXT);

	int stdout_copy = dup(STDOUT_FILENO);
	int test_num = 0;
	int my_fd;
	int lc_fd;
	int my_return;
	int lc_return;

	// Test 1
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", 0)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", 0);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", 0);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 2
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", -1)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", -1);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", -1);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 3
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", 1)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", 1);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", 1);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 4
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", 9)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", 9);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", 9);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 5
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", 10)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", 10);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", 10);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 6
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", 11)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", 11);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", 11);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 7
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", 15)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", 15);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", 15);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 8
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", 16)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", 16);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", 16);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 9
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", 17)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", 17);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", 17);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 10
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", 99)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", 99);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", 99);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 11
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", 100)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", 100);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", 100);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 12
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", 101)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", 101);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", 101);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 13
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", -9)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", -9);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", -9);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 14
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", -10)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", -10);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", -10);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 15
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", -11)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", -11);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", -11);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 16
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", -14)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", -14);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", -14);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 17
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", -15)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", -15);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", -15);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 18
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", -16)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", -16);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", -16);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 19
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", -99)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", -99);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", -99);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 20
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", -100)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", -100);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", -100);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 21
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", -101)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", -101);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", -101);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 22
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", INT_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", INT_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", INT_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 23
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", INT_MIN)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", INT_MIN);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", INT_MIN);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 24
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", LONG_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", LONG_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", LONG_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 25
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", LONG_MIN)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", LONG_MIN);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", LONG_MIN);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 26
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", UINT_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", UINT_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", UINT_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 27
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", ULONG_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", ULONG_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", ULONG_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 28
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", 9223372036854775807LL)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", 9223372036854775807LL);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", 9223372036854775807LL);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 29
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X %%X %%X %%X %%X %%X %%X\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 30
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", 42)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", 42);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", 42);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 31
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%X \", -42)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %X ", -42);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %X ", -42);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);
}

void x_test(void)
{
	printf(BLUE_TEXT "\n********\n%%x Tests\n********\n" RESET_TEXT);

	int stdout_copy = dup(STDOUT_FILENO);
	int test_num = 0;
	int my_fd;
	int lc_fd;
	int my_return;
	int lc_return;

	// Test 1
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", 0)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", 0);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", 0);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 2
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", -1)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", -1);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", -1);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 3
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", 1)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", 1);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", 1);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 4
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", 9)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", 9);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", 9);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 5
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", 10)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", 10);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", 10);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 6
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", 11)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", 11);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", 11);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 7
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", 15)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", 15);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", 15);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 8
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", 16)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", 16);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", 16);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 9
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", 17)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", 17);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", 17);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 10
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", 99)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", 99);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", 99);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 11
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", 100)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", 100);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", 100);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 12
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", 101)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", 101);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", 101);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 13
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", -9)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", -9);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", -9);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 14
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", -10)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", -10);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", -10);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 15
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", -11)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", -11);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", -11);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 16
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", -14)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", -14);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", -14);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 17
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", -15)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", -15);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", -15);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 18
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", -16)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", -16);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", -16);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 19
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", -99)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", -99);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", -99);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 20
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", -100)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", -100);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", -100);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 21
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", -101)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", -101);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", -101);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 22
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", INT_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", INT_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", INT_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 23
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", INT_MIN)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", INT_MIN);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", INT_MIN);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 24
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", LONG_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", LONG_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", LONG_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 25
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", LONG_MIN)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", LONG_MIN);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", LONG_MIN);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 26
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", UINT_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", UINT_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", UINT_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 27
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", ULONG_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", ULONG_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", ULONG_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 28
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", 9223372036854775807LL)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", 9223372036854775807LL);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", 9223372036854775807LL);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 29
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x %%x %%x %%x %%x %%x %%x\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 30
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", 42)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", 42);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", 42);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 31
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%x \", -42)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %x ", -42);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %x ", -42);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);
}

void u_test(void)
{
	printf(BLUE_TEXT "\n********\n%%u Tests\n********\n" RESET_TEXT);

	int stdout_copy = dup(STDOUT_FILENO);
	int test_num = 0;
	int my_fd;
	int lc_fd;
	int my_return;
	int lc_return;

	// Test 1
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", 0)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", 0);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", 0);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 2
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", -1)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", -1);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", -1);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 3
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", 1)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", 1);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", 1);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 4
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", 9)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", 9);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", 9);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 5
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", 10)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", 10);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", 10);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 6
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", 11)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", 11);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", 11);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 7
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", 15)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", 15);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", 15);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 8
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", 16)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", 16);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", 16);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 9
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", 17)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", 17);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", 17);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 10
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", 99)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", 99);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", 99);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 11
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", 100)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", 100);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", 100);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 12
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", 101)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", 101);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", 101);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 13
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", -9)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", -9);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", -9);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 14
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", -10)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", -10);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", -10);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 15
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", -11)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", -11);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", -11);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 16
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", -14)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", -14);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", -14);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 17
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", -15)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", -15);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", -15);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 18
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", -16)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", -16);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", -16);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 19
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", -99)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", -99);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", -99);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 20
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", -100)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", -100);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", -100);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 21
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", -101)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", -101);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", -101);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 22
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", INT_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", INT_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", INT_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 23
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", INT_MIN)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", INT_MIN);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", INT_MIN);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 24
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", LONG_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", LONG_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", LONG_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 25
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", LONG_MIN)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", LONG_MIN);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", LONG_MIN);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 26
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", UINT_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", UINT_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", UINT_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 27
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", ULONG_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", ULONG_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", ULONG_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 28
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u \", 9223372036854775807LL)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u ", 9223372036854775807LL);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u ", 9223372036854775807LL);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 29
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%u %%u %%u %%u %%u %%u %%u\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);
}

void i_test(void)
{
	printf(BLUE_TEXT "\n********\n%%i Tests\n********\n" RESET_TEXT);

	int stdout_copy = dup(STDOUT_FILENO);
	int test_num = 0;
	int my_fd;
	int lc_fd;
	int my_return;
	int lc_return;

	// Test 1
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", 0)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", 0);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", 0);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 2
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", -1)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", -1);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", -1);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 3
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", 1)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", 1);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", 1);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 4
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", 9)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", 9);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", 9);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 5
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", 10)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", 10);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", 10);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 6
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", 11)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", 11);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", 11);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 7
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", 15)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", 15);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", 15);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 8
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", 16)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", 16);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", 16);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 9
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", 17)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", 17);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", 17);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 10
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", 99)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", 99);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", 99);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 11
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", 100)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", 100);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", 100);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 12
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", 101)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", 101);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", 101);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 13
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", -9)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", -9);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", -9);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 14
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", -10)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", -10);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", -10);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 15
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", -11)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", -11);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", -11);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 16
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", -14)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", -14);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", -14);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 17
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", -15)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", -15);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", -15);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 18
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", -16)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", -16);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", -16);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 19
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", -99)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", -99);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", -99);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 20
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", -100)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", -100);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", -100);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 21
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", -101)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", -101);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", -101);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 22
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", INT_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", INT_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", INT_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 23
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", INT_MIN)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", INT_MIN);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", INT_MIN);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 24
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", LONG_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", LONG_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", LONG_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 25
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", LONG_MIN)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", LONG_MIN);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", LONG_MIN);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 26
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", UINT_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", UINT_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", UINT_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 27
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", ULONG_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", ULONG_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", ULONG_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 28
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i \", 9223372036854775807LL)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i ", 9223372036854775807LL);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i ", 9223372036854775807LL);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 29
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%i %%i %%i %%i %%i %%i %%i\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %i %i %i %i %i %i %i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %i %i %i %i %i %i %i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);
}

void d_test(void)
{
	printf(BLUE_TEXT "\n********\n%%d Tests\n********\n" RESET_TEXT);

	int stdout_copy = dup(STDOUT_FILENO);
	int test_num = 0;
	int my_fd;
	int lc_fd;
	int my_return;
	int lc_return;

	// Test 1
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", 0)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", 0);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", 0);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 2
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", -1)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", -1);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", -1);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 3
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", 1)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", 1);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", 1);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 4
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", 9)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", 9);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", 9);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 5
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", 10)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", 10);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", 10);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 6
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", 11)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", 11);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", 11);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 7
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", 15)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", 15);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", 15);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 8
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", 16)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", 16);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", 16);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 9
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", 17)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", 17);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", 17);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 10
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", 99)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", 99);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", 99);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 11
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", 100)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", 100);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", 100);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 12
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", 101)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", 101);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", 101);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 13
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", -9)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", -9);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", -9);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 14
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", -10)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", -10);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", -10);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 15
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", -11)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", -11);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", -11);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 16
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", -14)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", -14);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", -14);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 17
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", -15)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", -15);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", -15);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 18
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", -16)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", -16);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", -16);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 19
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", -99)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", -99);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", -99);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 20
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", -100)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", -100);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", -100);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 21
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", -101)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", -101);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", -101);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 22
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", INT_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", INT_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", INT_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 23
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", INT_MIN)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", INT_MIN);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", INT_MIN);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 24
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", LONG_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", LONG_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", LONG_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 25
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", LONG_MIN)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", LONG_MIN);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", LONG_MIN);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 26
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", UINT_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", UINT_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", UINT_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 27
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", ULONG_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", ULONG_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", ULONG_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 28
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d \", 9223372036854775807LL)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d ", 9223372036854775807LL);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d ", 9223372036854775807LL);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 29
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%d %%d %%d %%d %%d %%d %%d\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);
}

void p_test(void)
{
	printf(BLUE_TEXT "\n********\n%%p Tests\n********\n" RESET_TEXT);

	int stdout_copy = dup(STDOUT_FILENO);
	int test_num = 0;
	int my_fd;
	int lc_fd;
	int my_return;
	int lc_return;

	// Test 1
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%p \", -1)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %p ", -1);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %p ", -1);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 2
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%p \", 1)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %p ", 1);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %p ", 1);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 3
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%p \", 15)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %p ", 15);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %p ", 15);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 4
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%p \", 16)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %p ", 16);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %p ", 16);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 5
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%p \", 17)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %p ", 17);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %p ", 17);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 6
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%p %%p \", LONG_MIN, LONG_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %p %p ", LONG_MIN, LONG_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 7
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%p %%p \", INT_MIN, INT_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %p %p ", INT_MIN, INT_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %p %p ", INT_MIN, INT_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 8
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%p %%p \", ULONG_MAX, -ULONG_MAX)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 9
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%p %%p \", 0, 0)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %p %p ", 0, 0);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %p %p ", 0, 0);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);
}

void s_test(void)
{
	printf(BLUE_TEXT "\n********\n%%s Tests\n********\n" RESET_TEXT);

	int stdout_copy = dup(STDOUT_FILENO);
	int test_num = 0;
	int my_fd;
	int lc_fd;
	int my_return;
	int lc_return;
	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";

	// Test 1
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\"%%s\", \"\")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf("%s", "");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf("%s", "");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 2
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%s\", \"\")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %s", "");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %s", "");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 3
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\"%%s \", \"\")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf("%s ", "");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf("%s ", "");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 4
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%s \", \"\")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %s ", "");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %s ", "");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 5
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%s \", \"-\")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %s ", "-");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %s ", "-");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 6
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%s %%s \", \"\", \"-\")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %s %s ", "", "-");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %s %s ", "", "-");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 7
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%s %%s \", \" - \", \"\")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %s %s ", " - ", "");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %s %s ", " - ", "");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 8
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%s %%s %%s %%s %%s\", \" - \", \"\", \"4\", \"\", s2)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 9
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%s %%s %%s %%s %%s \", \" - \", \"\", \"4\", \"\", \"2 \")\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 10
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" NULL %%s NULL \", NULL)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" NULL %s NULL ", NULL);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" NULL %s NULL ", NULL);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);
}

void c_test(void)
{
	printf(BLUE_TEXT "\n********\n%%c Tests\n********\n" RESET_TEXT);

	int stdout_copy = dup(STDOUT_FILENO);
	int test_num = 0;
	int my_fd;
	int lc_fd;
	int my_return;
	int lc_return;

	// Test 1
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\"%%c\", '0')\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf("%c", '0');
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf("%c", '0');
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 2
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%c \", '0')\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %c ", '0');
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %c ", '0');
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 3
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%c\", '0' - 256)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %c", '0' - 256);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %c", '0' - 256);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 4
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%c\", '0' + 256)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %c", '0' + 256);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %c", '0' + 256);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 5
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%c %%c %%c \", '0', 0, '1')\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %c %c %c ", '0', 0, '1');
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %c %c %c ", '0', 0, '1');
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 6
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%c %%c %%c \", ' ', ' ', ' ')\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %c %c %c ", ' ', ' ', ' ');
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %c %c %c ", ' ', ' ', ' ');
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 7
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%c %%c %%c \", '1', '2', '3')\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %c %c %c ", '1', '2', '3');
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %c %c %c ", '1', '2', '3');
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 8
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%c %%c %%c \", '2', '1', 0)\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %c %c %c ", '2', '1', 0);
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %c %c %c ", '2', '1', 0);
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);

	// Test 9
	test_num++;
	printf(RESET_TEXT "\nTest %d\n" RESET_TEXT, test_num);
	printf("Input = ft_printf(\" %%c %%c %%c \", 0, '1', '2')\n");

	my_fd = open("my_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	fflush(stdout);
	dup2(my_fd, STDOUT_FILENO);
	my_return = ft_printf(" %c %c %c ", 0, '1', '2');
	fflush(stdout);
	close(my_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	lc_fd = open("libc_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(lc_fd, STDOUT_FILENO);
	lc_return = printf(" %c %c %c ", 0, '1', '2');
	fflush(stdout);
	close(lc_fd);
	dup2(stdout_copy, STDOUT_FILENO);

	compare_files(test_num);
	check_return(my_return, lc_return);
}

int main(void)
{
	c_test();
	s_test();
	p_test();
	d_test();
	i_test();
	u_test();
	x_test();
	X_test();
	percent_test();
	mix_test();
	return (0);
}