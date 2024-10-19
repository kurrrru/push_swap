/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_to_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:05:57 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 19:09:34 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_to_insert(t_deque *stack_a, int target)
{
	int	i;
	int	size;
	int	val1;
	int	val2;

	i = -1;
	size = deque_size(stack_a);
	while (++i < size)
	{
		val1 = deque_at_from_front(stack_a, (i + size - 1) % size);
		val2 = deque_at_from_front(stack_a, i);
		if (val1 < target && target < val2)
			return (i);
		if (val1 > val2 && (val1 < target || target < val2))
			return (i);
	}
	return (ERROR);
}