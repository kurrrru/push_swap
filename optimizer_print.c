/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:10:48 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 15:43:23 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	optimizer_print(t_optimizer *opt, t_op op, int count)
{
	opt->op_count[op] -= count;
	while (count--)
		ft_putendl_fd(opt->op_str[op], STDOUT_FILENO);
}
