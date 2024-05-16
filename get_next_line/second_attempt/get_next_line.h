/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:15:32 by jwhitley          #+#    #+#             */
/*   Updated: 2024/05/16 17:12:25 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

/* Main Functions */
char	*get_next_line(int fd);
char	*read_file(int	fd, char *total);
char	*next_line(char *total, size_t index);
char	*leftover(char *total, char *line, size_t index);
size_t	find_nl(char *total);

/* Helper Functions*/
void	*gnl_calloc(size_t nmemb, size_t size);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *str);

#endif
