/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 02:01:03 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/31 02:01:03 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// stack_push: push value to stack
// @ stack: pointer to stack
// @ value: value to push
// Push value to stack and increment top.
// return: 1 if success, 0 if stack is full
int	stack_push(t_stack *stack, int value)
{
	if (stack_size(stack) == stack->arr_len - 1)
		return (0);
	stack->top = (stack->top + 1) % stack->arr_len;
	stack->arr[stack->top] = value;
	return (1);
}

// stack_top: get top value of stack
// @ stack: pointer to stack
// If stack is empty, return dummy value INT_MIN.
// return: top value of stack, INT_MIN if stack is empty
int	stack_top(t_stack *stack)
{
	if (stack_empty(stack))
		return (INT_MIN);
	return (stack->arr[stack->top]);
}

// stack_pop: pop value from stack
// @ stack: pointer to stack
// If stack is empty, do nothing.
// return: none
void	stack_pop(t_stack *stack)
{
	if (stack_empty(stack))
		return ;
	stack->top = (stack->top - 1 + stack->arr_len) % stack->arr_len;
}
