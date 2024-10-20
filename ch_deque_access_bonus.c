/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_deque_access_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:23:21 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 12:23:22 by nkawaguc         ###   ########.fr       */
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
	if (!deque || index < 0 || index >= deque_size(deque))
		return (DEQUE_EXCEPTION_VALUE);
	return (deque->data[(deque->head - index + deque->limit) % deque->limit]);
}

int	deque_at_from_back(t_deque *deque, int index)
{
	if (!deque || index < 0 || index >= deque_size(deque))
		return (DEQUE_EXCEPTION_VALUE);
	return (deque->data[(deque->tail + index) % deque->limit]);
}
