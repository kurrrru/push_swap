/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:45:42 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/13 12:00:19 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	deque_front(t_deque *deque)
{
	if (!deque || deque_empty(deque))
		return (DEQUE_EXCEPTION_VALUE);
	return (deque->data[deque->head]);
}

int	deque_back(t_deque *deque)
{
	if (!deque || deque_empty(deque))
		return (DEQUE_EXCEPTION_VALUE);
	return (deque->data[deque->tail]);
}

int	deque_at_from_front(t_deque *deque, int index)
{
	if (!deque ||index < 0 || index >= deque_size(deque))
		return (DEQUE_EXCEPTION_VALUE);
	return (deque->data[(deque->head - index + deque->limit) % deque->limit]);
}

int	deque_at_from_back(t_deque *deque, int index)
{
	if (!deque || index < 0 || index >= deque_size(deque))
		return (DEQUE_EXCEPTION_VALUE);
	return (deque->data[(deque->tail + index) % deque->limit]);
}
