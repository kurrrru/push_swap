/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 01:19:29 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/31 01:19:29 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// stack_init: initialize stack
// @ max_size: max size of stack
// The size of stack is set to max_size + 1 to separate empty and full states.
// return: pointer to stack
t_stack	*stack_init()
{
	t_stack	*stack;
	int		i;
	int		max_size;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	max_size = 10000;
	stack->arr_len = max_size + 1;
	stack->bottom = 0;
	stack->top = -1;
	stack->max_size = max_size;
	return (stack);
}

// stack_free: free stack
// @ stack: pointer to stack
// return: none
void	stack_free(t_stack *stack)
{
	free(stack);
}

// stack_size: get size of stack
// @ stack: pointer to stack
// return: size of stack
size_t	stack_size(t_stack *stack)
{
	return ((stack->top - stack->bottom + 1 + stack->arr_len) % stack->arr_len);
}

// stack_empty: check if stack is empty
// @ stack: pointer to stack
// return: 1 if stack is empty, 0 otherwise
int	stack_empty(t_stack *stack)
{
	return (stack_size(stack) == 0);
}

// stack_at: get value at index from top of stack in O(1)
// @ stack: pointer to stack
// @ index: index from top of stack
// return: value at index from top of stack
int	stack_at(t_stack *stack, size_t index)
{
	if (index >= stack_size(stack))
		return (INT_MIN);
	return (stack->arr[(stack->top - index + stack->arr_len) % stack->arr_len]);
}
