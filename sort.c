/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:25:07 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 17:00:52 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort(t_deque *stack_a, t_deque *stack_b, int *input_array)
{
	t_optimizer	*opt;

	opt = optimizer_init();
	if (opt == NULL)
		error();
	sort_push_to_b(stack_a, stack_b, input_array, opt);
	sort_push_to_a(stack_a, stack_b, opt);
	optimizer_print(opt, OP_RA, opt->op_count[OP_RA]);
	optimizer_print(opt, OP_RRA, opt->op_count[OP_RRA]);
	optimizer_print(opt, OP_RB, opt->op_count[OP_RB]);
	optimizer_print(opt, OP_RRB, opt->op_count[OP_RRB]);
	optimizer_free(opt);
}
