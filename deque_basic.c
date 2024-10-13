/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:42:06 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/13 11:55:48 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque	*deque_init()
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	if (!deque)
		return (NULL);
	deque->data = (int *)malloc(sizeof(int) * DEQUE_DEFAULT_LIMIT);
	if (!deque->data)
	{
		free(deque);
		return (NULL);
	}
	deque->limit = DEQUE_DEFAULT_LIMIT;
	deque->head = deque->limit - 1;
	deque->tail = 0;
	return (deque);
}

void	deque_free(t_deque *deque)
{
	if (deque)
		free(deque->data);
	free(deque);
}

int	deque_size(t_deque *deque)
{
	if (!deque)
		return (DEQUE_EXCEPTION_VALUE);
	return ((deque->head - deque->tail + 1 + deque->limit) % deque->limit);
}

int	deque_empty(t_deque *deque)
{
	if (!deque)
		return (DEQUE_EXCEPTION_VALUE);
	return (deque_size(deque) == 0);
}
