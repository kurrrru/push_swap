/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:48:27 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/14 15:56:29 by nkawaguc         ###   ########.fr       */
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
		deque_push_front(stack_a, input_array[i]);
}
