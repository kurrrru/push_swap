/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:39:18 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/15 22:36:40 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "deque.h"
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0
# define FAILURE -1
# define SUCCESS 0
# define INF INT_MAX

# define VALID_ARGC_MIN 2
# define MSG_ERROR "Error"

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

#endif
