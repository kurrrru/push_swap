/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:23:59 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 14:23:43 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CH_BONUS_H
# define CH_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "ch_deque_bonus.h"
# include "ch_op_bonus.h"
# include "libft/libft.h"
# include "ch_basic_bonus.h"

# define INF INT_MAX
# define VALID_ARGC_MIN 2

// ch_checker_bonus.c
int		checker(int *input_array, int size);

// ch_check_instruction_bonus.c
int		is_correct_instruction(t_deque *stack_a, t_deque *stack_b);

// ch_empty_array_bonus.c
void	empty_array(void);

// ch_is_empty_array_bonus.c
int		is_empty_array(int argc);

// ch_is_duplicated_bonus.c
int		is_duplicated(int *arr, int size);

// ch_is_valid_string_bonus.c
int		is_valid_string(const char *str);

// ch_compress.c
void	compress(int *input_array, int size);

// ch_lower_bound_bonus.c
int		lower_bound(int *arr, int size, int target);

#endif
