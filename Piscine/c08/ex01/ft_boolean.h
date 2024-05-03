/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:43:48 by jwhitley          #+#    #+#             */
/*   Updated: 2024/02/27 18:27:56 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_BOOLEAN_H

#define FT_BOOLEAN_H

#include <unistd.h>

typedef int	t_bool;

#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"
#define SUCCESS 0
#define TRUE 1 
#define FALSE 0
#define EVEN(nbr) (nbr % 2 == 0)

#endif
