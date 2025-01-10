/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_file_opening.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cngogang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:03:53 by cngogang          #+#    #+#             */
/*   Updated: 2025/01/10 10:25:47 by cngogang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	put_user_input_in_temp_doc(int fd, t_redir *redirection)
{
	char	*input;
	int		i;

	i = 0;
	while (1)
	{
		input = readline("> ");
		if (input == NULL)
		{
			printf("Minishell: warning: here-document at line %i"
				"delimited by end-of-file (wanted : '%s')\n",
				i, redirection->filename);
			return ;
		}
		if (ft_strncmp(input, redirection->filename, ft_strlen(input)) == 0)
		{
			free(input);
			return ;
		}
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free(input);
		++i;
	}
}

static void	create_here_doc(t_redir *redirection)
{
	int		fd;

	signal(SIGINT, here_doc_open_behavior);
	if (!access(HERE_DOC_PATH, F_OK))
		unlink(HERE_DOC_PATH);
	fd = open(HERE_DOC_PATH, O_CREAT | O_RDWR | O_APPEND, 0777);
	put_user_input_in_temp_doc(fd, redirection);
	close (fd);
}

static int	open_infile(t_redir *redirection)
{
	int	fd;

	if (redirection->mode == 1)
	{
		create_here_doc(redirection);
		fd = open(HERE_DOC_PATH, O_RDONLY, 0777);
	}
	else
		fd = open((redirection)->filename, O_RDONLY, 0777);
	return (fd);
}

static int	open_outfile(t_redir *redirection)
{
	int	fd;

	if ((redirection)->mode == APPEND)
		fd = open((redirection)->filename, O_WRONLY | O_APPEND);
	else
	{
		fd = open((redirection)->filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	return (fd);
}

int	open_file(t_redir *redirection)
{
	int	fd;

	if ((redirection)->direction)
		fd = open_outfile(redirection);
	else
		fd = open_infile(redirection);
	return (fd);
}
