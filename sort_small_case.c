/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:37:12 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 14:58:36 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_deque *stack_a);
static void	sort_3(t_deque *stack_a, t_optimizer *opt);
static void	sort_4(t_deque *stack_a, t_deque *stack_b, t_optimizer *opt,
				int flag);
static void	sort_5(t_deque *stack_a, t_deque *stack_b, t_optimizer *opt);

void	sort_small_case(t_deque *stack_a, t_deque *stack_b, t_optimizer *opt)
{
	int	size;

	size = deque_size(stack_a);
	if (is_sorted(stack_a))
		return ;
	if (size == 2)
	{
		if (deque_front(stack_a) > deque_at_from_front(stack_a, 1))
			swap(stack_a, OP_SA, opt);
	}
	else if (size == 3)
		sort_3(stack_a, opt);
	else if (size == 4)
		sort_4(stack_a, stack_b, opt, TRUE);
	else if (size == 5)
		sort_5(stack_a, stack_b, opt);
}

static int	is_sorted(t_deque *stack_a)
{
	int	i;

	i = -1;
	while (++i < deque_size(stack_a) - 1)
	{
		if (deque_at_from_front(stack_a, i)
			> deque_at_from_front(stack_a, i + 1))
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

static void	sort_3(t_deque *stack_a, t_optimizer *opt)
{
	int	val0;
	int	val1;
	int	val2;

	val0 = deque_front(stack_a);
	val1 = deque_at_from_front(stack_a, 1);
	val2 = deque_at_from_front(stack_a, 2);
	if (val0 < val1 && val1 < val2)
		return ;
	if (val0 < val2 && val2 < val1)
	{
		swap(stack_a, OP_SA, opt);
		rotate_up(stack_a, OP_RA, opt);
	}
	else if (val1 < val0 && val0 < val2)
		swap(stack_a, OP_SA, opt);
	else if (val2 < val0 && val0 < val1)
		rotate_down(stack_a, OP_RRA, opt);
	else if (val1 < val2 && val2 < val0)
		rotate_up(stack_a, OP_RA, opt);
	else if (val2 < val1 && val1 < val0)
	{
		swap(stack_a, OP_SA, opt);
		rotate_down(stack_a, OP_RRA, opt);
	}
}

static void	sort_4(t_deque *stack_a, t_deque *stack_b, t_optimizer *opt,
				int flag)
{
	int	i;

	push(stack_a, stack_b, OP_PB, opt);
	sort_3(stack_a, opt);
	i = pos_to_insert(stack_a, deque_front(stack_b));
	if (i > deque_size(stack_a) / 2)
		i = i - deque_size(stack_a);
	if (i > 0)
	{
		while (i--)
			rotate_up(stack_a, OP_RA, opt);
	}
	else if (i < 0)
	{
		while (i++)
			rotate_down(stack_a, OP_RRA, opt);
	}
	push(stack_b, stack_a, OP_PA, opt);
	if (flag)
	{
		while (deque_front(stack_a) > deque_back(stack_a))
			rotate_up(stack_a, OP_RA, opt);
	}
}

static void	sort_5(t_deque *stack_a, t_deque *stack_b, t_optimizer *opt)
{
	int	i;

	push(stack_a, stack_b, OP_PB, opt);
	sort_4(stack_a, stack_b, opt, FALSE);
	i = pos_to_insert(stack_a, deque_front(stack_b));
	if (i > deque_size(stack_a) / 2)
		i = i - deque_size(stack_a);
	if (i > 0)
	{
		while (i--)
			rotate_up(stack_a, OP_RA, opt);
	}
	else
	{
		while (i++)
			rotate_down(stack_a, OP_RRA, opt);
	}
	push(stack_b, stack_a, OP_PA, opt);
	while (deque_front(stack_a) > deque_back(stack_a))
		rotate_up(stack_a, OP_RA, opt);
}
