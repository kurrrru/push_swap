/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:01:33 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 16:04:47 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include <unistd.h>
# include "deque.h"
# include "libft/libft.h"

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

typedef struct s_optimizer
{
	int		op_count[OP_RRR + 1];
	char	*op_str[OP_RRR + 1];
}	t_optimizer;

void		swap(t_deque *stack, t_op op, t_optimizer *opt);
void		push(t_deque *stack_from, t_deque *stack_to, t_op op,
				t_optimizer *opt);
void		rotate_up(t_deque *stack, t_op op, t_optimizer *opt);
void		rotate_down(t_deque *stack, t_op op, t_optimizer *opt);

t_optimizer	*optimizer_init(void);
void		optimizer_free(t_optimizer *opt);
void		optimizer_add(t_optimizer *opt, t_op op);
void		optimizer_print(t_optimizer *opt, t_op op, int count);

#endif
