/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 09:55:41 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 16:56:09 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void	optimizer_add_ra_rra(t_optimizer *opt, t_op op);
static void	optimizer_add_rb_rrb(t_optimizer *opt, t_op op);

void	optimizer_add(t_optimizer *opt, t_op op)
{
	if (op == OP_RA || op == OP_RRA)
		optimizer_add_ra_rra(opt, op);
	else if (op == OP_RB || op == OP_RRB)
		optimizer_add_rb_rrb(opt, op);
	else
	{
		optimizer_print(opt, OP_RA, opt->op_count[OP_RA]);
		optimizer_print(opt, OP_RRA, opt->op_count[OP_RRA]);
		optimizer_print(opt, OP_RB, opt->op_count[OP_RB]);
		optimizer_print(opt, OP_RRB, opt->op_count[OP_RRB]);
		ft_putendl_fd(opt->op_str[op], STDOUT_FILENO);
	}
}

static void	optimizer_add_ra_rra(t_optimizer *opt, t_op op)
{
	if (op == OP_RA)
	{
		if (opt->op_count[OP_RB] > 0)
		{
			ft_putendl_fd("rr", STDOUT_FILENO);
			opt->op_count[OP_RB]--;
		}
		else if (opt->op_count[OP_RRA] > 0)
			opt->op_count[OP_RRA]--;
		else
			opt->op_count[OP_RA]++;
	}
	else
	{
		if (opt->op_count[OP_RRB] > 0)
		{
			ft_putendl_fd("rrr", STDOUT_FILENO);
			opt->op_count[OP_RRB]--;
		}
		else if (opt->op_count[OP_RA] > 0)
			opt->op_count[OP_RA]--;
		else
			opt->op_count[OP_RRA]++;
	}
}

static void	optimizer_add_rb_rrb(t_optimizer *opt, t_op op)
{
	if (op == OP_RB)
	{
		if (opt->op_count[OP_RA] > 0)
		{
			ft_putendl_fd("rr", STDOUT_FILENO);
			opt->op_count[OP_RA]--;
		}
		else if (opt->op_count[OP_RRB] > 0)
			opt->op_count[OP_RRB]--;
		else
			opt->op_count[OP_RB]++;
	}
	else
	{
		if (opt->op_count[OP_RRA] > 0)
		{
			ft_putendl_fd("rrr", STDOUT_FILENO);
			opt->op_count[OP_RRA]--;
		}
		else if (opt->op_count[OP_RB] > 0)
			opt->op_count[OP_RB]--;
		else
			opt->op_count[OP_RRB]++;
	}
}
