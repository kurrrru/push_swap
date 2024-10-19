/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:07:16 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 16:05:31 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_optimizer	*optimizer_init(void)
{
	t_optimizer	*opt;

	opt = (t_optimizer *)malloc(sizeof(t_optimizer));
	if (!opt)
		return (NULL);
	ft_bzero(opt->op_count, sizeof(int) * (OP_RRR + 1));
	opt->op_str[OP_SA] = "sa";
	opt->op_str[OP_SB] = "sb";
	opt->op_str[OP_SS] = "ss";
	opt->op_str[OP_PA] = "pa";
	opt->op_str[OP_PB] = "pb";
	opt->op_str[OP_RA] = "ra";
	opt->op_str[OP_RB] = "rb";
	opt->op_str[OP_RR] = "rr";
	opt->op_str[OP_RRA] = "rra";
	opt->op_str[OP_RRB] = "rrb";
	opt->op_str[OP_RRR] = "rrr";
	return (opt);
}
