/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshw <joshw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:50:38 by joshw             #+#    #+#             */
/*   Updated: 2024/09/11 13:00:13 by joshw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_size.h"
#include <stdlib.h>

int ft_list_size(t_list *begin_list)
{
    int i;

    i = 0;
    while (begin_list)
    {
        begin_list = begin_list->next;
        i++;
    }
    return (i);
}