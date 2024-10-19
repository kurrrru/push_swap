/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:10:00 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 19:27:24 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_push_to_b(t_deque *stack_a, t_deque *stack_b, int *input_array,
			t_optimizer *opt)
{
	int	*lis_array;
	int	lis_size;
	int	i;
	int	j;
	int	size;

	size = deque_size(stack_a);
	lis_array = lis(input_array, size, &lis_size);
	if (lis_array == NULL)
		error();
	if (lis_size == size)
	{
		free(lis_array);
		return ;
	}
	i = -1;
	j = 0;
	while (++i < size)
	{
		if (j < lis_size && lis_array[j] == deque_front(stack_a))
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
		{
			push(stack_a, stack_b, OP_PB, opt);
		}
	}
	free(lis_array);
}
