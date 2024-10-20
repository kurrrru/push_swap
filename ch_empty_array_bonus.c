/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_empty_array_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:04:29 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 13:04:30 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_bonus.h"

void	empty_array(void)
{
	char	*buf[1];
	int		read_size;

	read_size = read(STDIN_FILENO, buf, 1);
	if (read_size == 0)
	{
		ft_putendl_fd(MSG_OK, STDOUT_FILENO);
		exit(SUCCESS);
	}
	else
	{
		ft_putendl_fd(MSG_KO, STDOUT_FILENO);
		exit(FAILURE);
	}
}
