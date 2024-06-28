/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 02:20:03 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/31 02:20:03 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int		*arr;
	int		arr_len;
	int		bottom;
	int		top;
	int		max_size;
}		t_stack;

t_stack	*stack_init();
void	stack_free(t_stack *stack);
size_t	stack_size(t_stack *stack);
int		stack_empty(t_stack *stack);
int		stack_at(t_stack *stack, size_t index);
int		stack_push(t_stack *stack, int value);
int		stack_top(t_stack *stack);
void	stack_pop(t_stack *stack);
void	stack_rotate_up(t_stack *stack);
void	stack_rotate_down(t_stack *stack);
void	stack_swap(t_stack *stack);

#endif
