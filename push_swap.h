/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:39:18 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 23:18:37 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "deque.h"
# include "libft/libft.h"
# include "op.h"

# define TRUE 1
# define FALSE 0
# define FAILURE -1
# define SUCCESS 0
# define ERROR -1
# define INF INT_MAX

# define VALID_ARGC_MIN 2
# define MSG_ERROR "Error"

typedef struct s_best
{
	int	target;
	int	rotate_a;
	int	rotate_b;
}	t_best;

// push_swap.c
void	push_swap(int *input_array, int size);

// is_valid_string.c
int		is_valid_string(const char *str);

// compress.c
void	compress(int *input_array, int size);

// lower_bound.c
int		lower_bound(int *arr, int size, int target);

// lis.c
int		*lis(int *arr, int size, int *lis_size);

// error.c
void	error(void);

// is_empty_array.c
int		is_empty_array(int argc);

// is_duplicated.c
int		is_duplicated(int *arr, int size);

// sort.c
void	sort(t_deque *stack_a, t_deque *stack_b, int *input_array);

// sort_push_to_b.c
void	sort_push_to_b(t_deque *stack_a, t_deque *stack_b, int *input_array,
			t_optimizer *opt);

// sort_push_to_a.c
void	sort_push_to_a(t_deque *stack_a, t_deque *stack_b, t_optimizer *opt);

// sort_small_case.c
void	sort_small_case(t_deque *stack_a, t_deque *stack_b, t_optimizer *opt);

// pos_to_insert.c
int		pos_to_insert(t_deque *stack_a, int target);

// multiple_rotate.c
void	multiple_rotate_a(t_deque *stack_a, int rotate_a, t_optimizer *opt);
void	multiple_rotate_b(t_deque *stack_b, int rotate_b, t_optimizer *opt);

#endif
