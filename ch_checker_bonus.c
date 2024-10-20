/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:48:27 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 13:23:14 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_bonus.h"

int	checker(int *input_array, int size)
{
	t_deque	*stack_a;
	t_deque	*stack_b;
	int		i;
	int		result;

	compress(input_array, size);
	stack_a = deque_init();
	stack_b = deque_init();
	if (stack_a == NULL || stack_b == NULL)
		error();
	i = -1;
	while (++i < size)
		deque_push_back(stack_a, input_array[i]);
	result = is_correct_instruction(stack_a, stack_b);
	deque_free(stack_a);
	deque_free(stack_b);
	return (result);
}
