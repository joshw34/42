/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:33:13 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/04 15:33:14 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_realpwd(void)
{
	char	*ret;

	ret = ft_calloc(1024, sizeof(char));
	getcwd(ret, 1024);
	return (ret);
}
