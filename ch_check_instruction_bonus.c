/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_check_instruction_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:05:06 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 14:53:02 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_bonus.h"

static int	get_op(t_op *op);
static int	is_valid_op(t_op *op, char *buf);
static void	run_op(t_deque *stack_a, t_deque *stack_b, t_op op);
static int	is_sorted(t_deque *stack_a);

int	is_correct_instruction(t_deque *stack_a, t_deque *stack_b)
{
	t_op	op;
	int		result;

	while (TRUE)
	{
		result = get_op(&op);
		if (result == FALSE)
			break ;
		run_op(stack_a, stack_b, op);
	}
	if (is_sorted(stack_a) && deque_empty(stack_b))
		return (TRUE);
	return (FALSE);
}

static int	get_op(t_op *op)
{
	char	buf[4];
	int		read_size;

	ft_bzero(buf, 4);
	read_size = read(STDIN_FILENO, buf, 3);
	if (read_size == ERROR || read_size == 1 || read_size == 2)
		error();
	if (read_size == 0)
		return (FALSE);
	if (buf[2] == '\n')
		buf[2] = '\0';
	else
	{
		read_size = read(STDIN_FILENO, buf + 3, 1);
		if (read_size == ERROR || buf[3] != '\n')
			error();
		buf[3] = '\0';
	}
	return (is_valid_op(op, buf));
}

static int	is_valid_op(t_op *op, char *buf)
{
	if (ft_strncmp(buf, OP_SA_STR, OP_SA_STR_LEN + 1) == 0)
		*op = OP_SA;
	else if (ft_strncmp(buf, OP_SB_STR, OP_SB_STR_LEN + 1) == 0)
		*op = OP_SB;
	else if (ft_strncmp(buf, OP_SS_STR, OP_SS_STR_LEN + 1) == 0)
		*op = OP_SS;
	else if (ft_strncmp(buf, OP_PA_STR, OP_PA_STR_LEN + 1) == 0)
		*op = OP_PA;
	else if (ft_strncmp(buf, OP_PB_STR, OP_PB_STR_LEN + 1) == 0)
		*op = OP_PB;
	else if (ft_strncmp(buf, OP_RA_STR, OP_RA_STR_LEN + 1) == 0)
		*op = OP_RA;
	else if (ft_strncmp(buf, OP_RB_STR, OP_RB_STR_LEN + 1) == 0)
		*op = OP_RB;
	else if (ft_strncmp(buf, OP_RR_STR, OP_RR_STR_LEN + 1) == 0)
		*op = OP_RR;
	else if (ft_strncmp(buf, OP_RRA_STR, OP_RRA_STR_LEN + 1) == 0)
		*op = OP_RRA;
	else if (ft_strncmp(buf, OP_RRB_STR, OP_RRB_STR_LEN + 1) == 0)
		*op = OP_RRB;
	else if (ft_strncmp(buf, OP_RRR_STR, OP_RRR_STR_LEN + 1) == 0)
		*op = OP_RRR;
	else
		error();
	return (TRUE);
}

static void	run_op(t_deque *stack_a, t_deque *stack_b, t_op op)
{
	if (op == OP_SA || op == OP_SS)
		swap(stack_a);
	if (op == OP_SB || op == OP_SS)
		swap(stack_b);
	if (op == OP_PA)
		push(stack_b, stack_a);
	if (op == OP_PB)
		push(stack_a, stack_b);
	if (op == OP_RA || op == OP_RR)
		rotate_up(stack_a);
	if (op == OP_RB || op == OP_RR)
		rotate_up(stack_b);
	if (op == OP_RRA || op == OP_RRR)
		rotate_down(stack_a);
	if (op == OP_RRB || op == OP_RRR)
		rotate_down(stack_b);
}

static int	is_sorted(t_deque *stack_a)
{
	int	i;

	i = -1;
	while (++i < deque_size(stack_a) - 1)
	{
		if (deque_at_from_front(stack_a, i)
			> deque_at_from_front(stack_a, i + 1))
		{
			return (FALSE);
		}
	}
	return (TRUE);
}
