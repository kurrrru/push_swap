/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:05:56 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 13:50:29 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	swap(t_deque *stack, t_op op, t_optimizer *opt)
{
	deque_swap_front(stack);
	optimizer_add(opt, op);
}

void	push(t_deque *stack_from, t_deque *stack_to, t_op op, t_optimizer *opt)
{
	if (deque_empty(stack_from))
		return ;
	deque_push_front(stack_to, deque_front(stack_from));
	deque_pop_front(stack_from);
	optimizer_add(opt, op);
}

void	rotate_up(t_deque *stack, t_op op, t_optimizer *opt)
{
	deque_rotate_front(stack);
	optimizer_add(opt, op);
}

void	rotate_down(t_deque *stack, t_op op, t_optimizer *opt)
{
	deque_rotate_back(stack);
	optimizer_add(opt, op);
}
