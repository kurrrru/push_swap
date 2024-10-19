/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:10:00 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 22:58:02 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	push_to_b(t_deque *stack_a, t_deque *stack_b, int *lis_array,
				t_optimizer *opt);

void	sort_push_to_b(t_deque *stack_a, t_deque *stack_b, int *input_array,
			t_optimizer *opt)
{
	int	*lis_array;
	int	lis_size;
	int	size;

	size = deque_size(stack_a);
	lis_array = lis(input_array, size, &lis_size);
	if (lis_array == NULL)
		error();
	if (lis_size == size)
		return (free(lis_array));
	push_to_b(stack_a, stack_b, lis_array, opt);
	free(lis_array);
}

static void	push_to_b(t_deque *stack_a, t_deque *stack_b, int *lis_array,
				t_optimizer *opt)
{
	int	i;
	int	j;
	int	size;

	size = deque_size(stack_a);
	i = -1;
	j = 0;
	while (++i < size && lis_array[deque_size(stack_a) - 1] == INF)
	{
		if (lis_array[j] != INF && lis_array[j] == deque_front(stack_a))
		{
			if ((j == 0 || lis_array[j - 1] < deque_at_from_front(stack_a, 1))
				&& (lis_array[j] > deque_at_from_front(stack_a, 1)))
			{
				swap(stack_a, OP_SA, opt);
				rotate_up(stack_a, OP_RA, opt);
				i++;
			}
			rotate_up(stack_a, OP_RA, opt);
			j++;
		}
		else
			push(stack_a, stack_b, OP_PB, opt);
	}
}
