/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_op_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:05:56 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 13:49:05 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_op_bonus.h"

void	swap(t_deque *stack)
{
	deque_swap_front(stack);
}

void	push(t_deque *stack_from, t_deque *stack_to)
{
	if (deque_empty(stack_from))
		return ;
	deque_push_front(stack_to, deque_front(stack_from));
	deque_pop_front(stack_from);
}

void	rotate_up(t_deque *stack)
{
	deque_rotate_front(stack);
}

void	rotate_down(t_deque *stack)
{
	deque_rotate_back(stack);
}
