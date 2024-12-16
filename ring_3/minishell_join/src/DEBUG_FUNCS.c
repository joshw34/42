#include "../inc/minishell.h"

void	DB_print_array(char **array)
{
	int	i = 0;
	while (array[i])
	{
		printf("%d\t%s\n", i, array[i]);
		i++;
	}
}

void	DB_print_tokens(t_data *data)
{
	t_tokens *temp = data->tokens;

	while (temp != NULL)
	{
		printf("TOKEN: %d\n", temp->i);
		printf("Word: %s\n", temp->word);
		printf("Sep: %s\n", temp->sep);
		printf("Quotes: %d\n", temp->quote);
		printf("Processed: %d\n", temp->processed);
		printf("\n");
		temp = temp->next;
	}
}

void	DB_print_cmds(t_data *data)
{
	t_cmd	*temp = data->cmds;
	int		i = 1;

	while (temp != NULL)
	{
		printf("\nCOMMAND #%d\n", i);
		printf("cmd_n = %d\n", temp->cmd_n);
		printf("Command: %s\n", temp->cmd);
		printf("fd_in: %d\nfd_out: %d\n", temp->fd_in, temp->fd_out);
		printf("located at: %p\n", temp);
		printf("Prev: %p\n", temp->prev);
		printf("Next: %p\n", temp->next);
		DB_print_input_redir(temp->in);
		DB_print_output_redir(temp->out);
		temp = temp->next;
		i++;
	}
}

void	DB_print_output_redir(t_redir *output)
{
	printf("\nOUTPUT REDIRECTION:\n");
	if (output == NULL)
		printf("No Output Redirection\n");
	else
	{
		while (output != NULL)
		{
			printf("Filename: %s\n", output->filename);
			printf("Direction (0 = in, 1 = out): %d\n", output->direction);
			printf("Mode (2 = outfile, 3 = apppend): %d\n", output->mode);
			output = output->next;
		}
	}
}

void	DB_print_input_redir(t_redir *input)
{
	printf("\nINPUT REDIRECTION:\n");
	if (input == NULL)
		printf("No Input Redirection\n");
	else
	{
		while (input != NULL)
		{
			printf("Filename: %s\n", input->filename);
			printf("Direction (0 = in, 1 = out): %d\n", input->direction);
			printf("Mode (0 = infile, 1 = heredoc): %d\n", input->mode);
			input = input->next;
		}
	}
}
