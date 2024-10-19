/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:22:18 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 19:41:33 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	multiple_rotate_a(t_deque *stack_a, int rotate_a, t_optimizer *opt);
static void	multiple_rotate_b(t_deque *stack_b, int rotate_b, t_optimizer *opt);
static void find_best(t_deque *stack_a, t_deque *stack_b, t_best *best);
static int	calc_num_op(int rotate_a, int rotate_b);

void	sort_push_to_a(t_deque *stack_a, t_deque *stack_b, t_optimizer *opt)
{
	t_best	best;
	int		small_index;

	while (deque_size(stack_b))
	{
		find_best(stack_a, stack_b, &best);
		multiple_rotate_a(stack_a, best.rotate_a, opt);
		multiple_rotate_b(stack_b, best.rotate_b, opt);
		push(stack_b, stack_a, OP_PA, opt);
	}
	small_index = deque_find(stack_a, 0);
	if (small_index > deque_size(stack_a) / 2)
		small_index = small_index - deque_size(stack_a);
	multiple_rotate_a(stack_a, small_index, opt);
}

static void	find_best(t_deque *stack_a, t_deque *stack_b, t_best *best)
{
	int	*pos_a;
	int	*pos_b;
	int	i;
	int	now_min;

	pos_a = (int *)malloc(sizeof(int) * deque_size(stack_b));
	pos_b = (int *)malloc(sizeof(int) * deque_size(stack_b));
	if (pos_a == NULL || pos_b == NULL)
		error();
	i = -1;
	now_min = INF;
	while (++i < deque_size(stack_b))
	{
		pos_a[i] = pos_to_insert(stack_a, deque_at_from_front(stack_b, i));
		if (pos_a[i] > deque_size(stack_a) / 2)
			pos_a[i] = pos_a[i] - deque_size(stack_a);
		pos_b[i] = i;
		if (pos_b[i] > deque_size(stack_b) / 2)
			pos_b[i] = pos_b[i] - deque_size(stack_b);
		if (now_min > calc_num_op(pos_a[i], pos_b[i]))
		{
			now_min = calc_num_op(pos_a[i], pos_b[i]);
			best->target = deque_at_from_front(stack_b, i);
			best->rotate_a = pos_a[i];
			best->rotate_b = pos_b[i];
		}
	}
	free(pos_a);
	free(pos_b);
}

static void	multiple_rotate_a(t_deque *stack_a, int rotate_a, t_optimizer *opt)
{
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

static void	multiple_rotate_b(t_deque *stack_b, int rotate_b, t_optimizer *opt)
{
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

static int	calc_num_op(int rotate_a, int rotate_b)
{
	if (rotate_a > 0 && rotate_b > 0)
	{
		if (rotate_a > rotate_b)
			return (rotate_a);
		else
			return (rotate_b);
	}
	else if (rotate_a < 0 && rotate_b < 0)
	{
		if (rotate_a < rotate_b)
			return (-rotate_a);
		else
			return (-rotate_b);
	}
	else if (rotate_a > 0 && rotate_b < 0)
		return (rotate_a - rotate_b);
	else
		return (rotate_b - rotate_a);
}

