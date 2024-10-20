/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:55:06 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 13:44:57 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_basic_bonus.h"

void	error(void)
{
	ft_putendl_fd(MSG_ERROR, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
