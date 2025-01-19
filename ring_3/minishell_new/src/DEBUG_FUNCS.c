/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG_FUNCS.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:41:20 by cngogang          #+#    #+#             */
/*   Updated: 2025/01/19 22:25:36 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	db_print_with_seps(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 31)
			write(1, "*", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}



void	db_print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("%d\t%s\n", i, array[i]);
		i++;
	}
}

void	db_print_tokens(t_data *data)
{
	t_tokens	*temp;

	temp = data->tokens;
	while (temp != NULL)
	{
		printf("TOKEN: %d\n", temp->i);
		printf("Word: *%s*\n", temp->word);
		printf("Sep: %s\n", temp->sep);
		printf("Type: %d\n", temp->type);
		printf("Processed: %d\n", temp->processed);
		printf("\n");
		temp = temp->next;
	}
}

void	db_print_cmds(t_data *data)
{
	t_cmd	*temp;
	int		i;

	temp = data->cmds;
	i = 0;
	while (temp != NULL)
	{
		printf("\nCOMMAND #%d\n", i);
		printf("cmd_n = %d\n", temp->cmd_n);
		printf("Command: %s\n", temp->cmd);
		printf("fd_in: %d\nfd_out: %d\n", temp->fd_in, temp->fd_out);
		printf("located at: %p\n", temp);
		printf("Prev: %p\n", temp->prev);
		printf("Next: %p\n", temp->next);
		db_print_input_redir(temp->in);
		db_print_output_redir(temp->out);
		db_print_array(temp->args);
		temp = temp->next;
		i++;
	}
}

void	db_print_output_redir(t_redir *output)
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

void	db_print_input_redir(t_redir *input)
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
