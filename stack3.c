/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 02:00:55 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/31 02:00:55 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// stack_rotate_up: rotate stack up
// @ stack: pointer to stack
// If stack is empty, do nothing.
// Rotate stack up by one. The top value is moved to the bottom.
// return: none
void	stack_rotate_up(t_stack *stack)
{
	if (stack_empty(stack))
		return ;
	stack->bottom = (stack->bottom - 1 + stack->arr_len) % stack->arr_len;
	stack->arr[stack->bottom] = stack->arr[stack->top];
	stack->top = (stack->top - 1 + stack->arr_len) % stack->arr_len;
}

// stack_rotate_down: rotate stack down
// @ stack: pointer to stack
// If stack is empty, do nothing.
// Rotate stack down by one. The bottom value is moved to the top.
// return: none
void	stack_rotate_down(t_stack *stack)
{
	if (stack_empty(stack))
		return ;
	stack->top = (stack->top + 1) % stack->arr_len;
	stack->arr[stack->top] = stack->arr[stack->bottom];
	stack->bottom = (stack->bottom + 1) % stack->arr_len;
}

// stack_swap: swap top two values of stack
// @ stack: pointer to stack
// If stack has less than 2 values, do nothing.
// return: none
void	stack_swap(t_stack *stack)
{
	int	tmp;
	int	top_before;

	if (stack_size(stack) < 2)
		return ;
	tmp = stack->arr[stack->top];
	top_before = (stack->top - 1 + stack->arr_len) % stack->arr_len;
	stack->arr[stack->top] = stack->arr[top_before];
	stack->arr[top_before] = tmp;
}

// void	stack_display(t_stack *stack)
// {
// 	size_t	i;
//	size_t	size;

// 	i = 0;
// 	size = stack_size(stack);
// 	while (i < size)
// 		ft_printf("%d ", stack_at(stack, i++));
// 	ft_printf("\n");
// }
