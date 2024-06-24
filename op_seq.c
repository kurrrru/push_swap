/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_seq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 02:09:54 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/06/24 02:13:17 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_seq.h"

t_op_seq	*op_seq_init()
{
	t_op_seq	*op;

	op = (t_op_seq *)malloc(sizeof(t_op_seq));
	op->len = 0;
	return (op);
}

void	op_seq_free(t_op_seq *op)
{
	free(op);
}

void	op_seq_push(t_op_seq *op, char *op_str)
{
	op->arr[op->len] = op_str;
	op->len++;
}