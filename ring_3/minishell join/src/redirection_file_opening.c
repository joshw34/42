/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_file_opening.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cngogang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:03:53 by cngogang          #+#    #+#             */
/*   Updated: 2024/12/13 10:03:55 by cngogang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int open_infile (t_redir *redirection)
{
	int	fd;

	fd = open((redirection)->filename, O_RDONLY, 0777);
	//printf("Open infile fd == %i\n", fd);
	return (fd);
}

static int open_outfile (t_redir *redirection)
{
	int	fd;

	//printf("strcmp value  == %i && {APPOND} == %i\n", ft_strncmp((redirection)->mode, "APPEND", 6), ft_strncmp((redirection)->mode, "APPOND", 6));
	if ((redirection)->mode == APPEND)
		{
			
			fd = open((redirection)->filename, O_WRONLY | O_APPEND);
			//printf("Outfile append mode fd == %i\n", fd);
		}
	else
	{
		fd = open((redirection)->filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		//printf("Outfile OPen mode fd == %i\n", fd);
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
