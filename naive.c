/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:56:29 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/06/24 03:00:12 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *a, t_stack *b, int size, t_op_seq *op)
{
	if (size == 1 || (size == 2 && stack_at(a, 0) < stack_at(a, 1)))
		return ;
	if (size == 2 && stack_at(a, 0) > stack_at(a, 1))
		return (op_seq_push(op, "sa"), stack_swap(a));
	if (stack_at(a, 0) > stack_at(a, 1) && stack_at(a, 1) > stack_at(a, 2)) // 321
		return (op_seq_push(op, "sa"), op_seq_push(op, "rra"), stack_swap(a), stack_rotate_down(a));
	if (stack_at(a, 0) > stack_at(a, 2) && stack_at(a, 2) > stack_at(a, 1)) // 312
		return (op_seq_push(op, "ra"), stack_rotate_up(a));
	if (stack_at(a, 1) > stack_at(a, 0) && stack_at(a, 0) > stack_at(a, 2)) // 231
		return (op_seq_push(op, "rra"), stack_rotate_down(a));
	if (stack_at(a, 1) > stack_at(a, 2) && stack_at(a, 2) > stack_at(a, 0)) // 132
		return (op_seq_push(op, "sa"), op_seq_push(op, "ra"), stack_swap(a), stack_rotate_up(a));
	if (stack_at(a, 2) > stack_at(a, 0) && stack_at(a, 0) > stack_at(a, 1)) // 213
		return (op_seq_push(op, "sa"), stack_swap(a));
	if (stack_at(a, 2) > stack_at(a, 1) && stack_at(a, 1) > stack_at(a, 0)) // 123
		return ;
}

void	sort_naive(t_stack *a, t_stack *b, int size, t_op_seq *op)
{
	int	i;
	int	min_i;
	int	min;

	if (size <= 3)
		return (sort_small(a, b, size, op));
	i = -1;
	min_i = 0;
	min = stack_at(a, 0);
	while (++i < size)
		if (stack_at(a, i) < stack_at(a, min_i))
		{
			min_i = i;
			min = stack_at(a, i);
		}
	if (min_i < stack_size(a) / 2)
		while (stack_at(a, 0) != min)
		{
			op_seq_push(op, "ra");
			stack_rotate_up(a);
		}
	else
		while (stack_at(a, 0) != min)
		{
			op_seq_push(op, "rra");
			stack_rotate_down(a);
		}
	op_seq_push(op, "pb");
	stack_push(b, stack_top(a));
	stack_pop(a);
	sort_naive(a, b, size - 1, op);
	op_seq_push(op, "pa");
	stack_push(a, stack_top(b));
	stack_pop(b);
}

// null check -> "Error" ?
int main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_op_seq	*op;

	// for (int i = 0; i < 5; i++)
	// 	for (int j = 0; j < 5; j++)
	// 		for (int k = 0; k < 5; k++)
	// 			for (int l = 0; l < 5; l++)
	// 				for (int m = 0; m < 5; m++)
	// 				{
	// 					if (i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m)
	// 						continue;
	// 								a = stack_init();
	// 					b = stack_init();
	// 					op = op_seq_init();
	// 					if (!a || !b || !op)
	// 						return (stack_free(a), stack_free(b), op_seq_free(op), 1);
	// 					stack_push(a, i);
	// 					stack_push(a, j);
	// 					stack_push(a, k);
	// 					stack_push(a, l);
	// 					stack_push(a, m);
	// 					printf("array: %d %d %d %d %d\n", stack_at(a, 0), stack_at(a, 1), stack_at(a, 2), stack_at(a, 3), stack_at(a, 4));
	// 					sort_naive(a, b, stack_size(a), op);
	// 					printf("array: %d %d %d %d %d\n", stack_at(a, 0), stack_at(a, 1), stack_at(a, 2), stack_at(a, 3), stack_at(a, 4));
	// 					printf("op: %d\n", op->len);
	// 					for (size_t i = 0; i < op->len; i++)
	// 						printf("%s%c", op->arr[i], " \n"[i == op->len - 1]);
	// 					printf("\n");
	// 					stack_free(a);
	// 					stack_free(b);
	// 					op_seq_free(op);
	// 				}



	if (argc < 2)
		return (1);

	a = stack_init();
	b = stack_init();
	op = op_seq_init();
	if (!a || !b || !op)
		return (stack_free(a), stack_free(b), op_seq_free(op), 1);
	for (int i = argc - 1; i > 0; i--)
		stack_push(a, atoi(argv[i]));
	sort_naive(a, b, stack_size(a), op);
	for (size_t i = 0; i < op->len; i++)
		printf("%s\n", op->arr[i]);
	stack_free(a);
	stack_free(b);
	op_seq_free(op);
}
