/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:48:27 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 17:04:09 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *input_array, int size)
{
	t_deque	*stack_a;
	t_deque	*stack_b;
	int		i;

	compress(input_array, size);
	stack_a = deque_init();
	stack_b = deque_init();
	if (stack_a == NULL || stack_b == NULL)
		error();
	i = -1;
	while (++i < size)
		deque_push_back(stack_a, input_array[i]);
	sort(stack_a, stack_b, input_array);
	deque_free(stack_a);
	deque_free(stack_b);
}
