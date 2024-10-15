/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:25:07 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/15 23:01:57 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort(t_deque *stack_a, t_deque *stack_b, int *input_array)
{
	int	*lis_array;
	int	lis_size;
	int	i;

	lis_array = lis(input_array, deque_size(stack_a), &lis_size);
	if (lis_array == NULL)
		error();
	i = -1;
	while (++i < lis_size)
		printf("%d\n", lis_array[i]);
	free(lis_array);
	(void)stack_b;
}