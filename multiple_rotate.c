/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:07:37 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 23:07:38 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	multiple_rotate_a(t_deque *stack_a, int rotate_a, t_optimizer *opt)
{
	if (rotate_a == 0)
		return ;
	if (rotate_a > 0)
	{
		while (rotate_a--)
			rotate_up(stack_a, OP_RA, opt);
	}
	else
	{
		while (rotate_a++)
			rotate_down(stack_a, OP_RRA, opt);
	}
}

void	multiple_rotate_b(t_deque *stack_b, int rotate_b, t_optimizer *opt)
{
	if (rotate_b == 0)
		return ;
	if (rotate_b > 0)
	{
		while (rotate_b--)
			rotate_up(stack_b, OP_RB, opt);
	}
	else
	{
		while (rotate_b++)
			rotate_down(stack_b, OP_RRB, opt);
	}
}
