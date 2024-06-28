/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_seq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 02:10:06 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/06/28 22:52:52 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_SEQ_H
# define OP_SEQ_H

# include <stdlib.h>

typedef struct s_op_seq
{
	char	*arr[100000];
	int		len;
}				t_op_seq;

t_op_seq	*op_seq_init();
void		op_seq_free(t_op_seq *op);
void		op_seq_push(t_op_seq *op, char *op_str);

#endif