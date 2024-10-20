/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_op_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:01:33 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 13:46:25 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CH_OP_BONUS_H
# define CH_OP_BONUS_H

# include <unistd.h>
# include "ch_deque_bonus.h"
# include "libft/libft.h"
# include "ch_basic_bonus.h"

# define OP_SA_STR "sa"
# define OP_SB_STR "sb"
# define OP_SS_STR "ss"
# define OP_PA_STR "pa"
# define OP_PB_STR "pb"
# define OP_RA_STR "ra"
# define OP_RB_STR "rb"
# define OP_RR_STR "rr"
# define OP_RRA_STR "rra"
# define OP_RRB_STR "rrb"
# define OP_RRR_STR "rrr"

# define OP_SA_STR_LEN 2
# define OP_SB_STR_LEN 2
# define OP_SS_STR_LEN 2
# define OP_PA_STR_LEN 2
# define OP_PB_STR_LEN 2
# define OP_RA_STR_LEN 2
# define OP_RB_STR_LEN 2
# define OP_RR_STR_LEN 2
# define OP_RRA_STR_LEN 3
# define OP_RRB_STR_LEN 3
# define OP_RRR_STR_LEN 3

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
}	t_op;

void	swap(t_deque *stack);
void	push(t_deque *stack_from, t_deque *stack_to);
void	rotate_up(t_deque *stack);
void	rotate_down(t_deque *stack);

#endif
