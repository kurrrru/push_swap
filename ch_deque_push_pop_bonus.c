/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_deque_push_pop_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:23:38 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 15:02:10 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_push_front(t_deque *deque, int value)
{
	if (!deque)
		return ;
	deque->head = (deque->head + 1) % deque->limit;
	deque->data[deque->head] = value;
}

void	deque_push_back(t_deque *deque, int value)
{
	if (!deque)
		return ;
	deque->tail = (deque->tail - 1 + deque->limit) % deque->limit;
	deque->data[deque->tail] = value;
}

void	deque_pop_front(t_deque *deque)
{
	if (!deque || deque_empty(deque))
		return ;
	deque->head = (deque->head - 1 + deque->limit) % deque->limit;
}

void	deque_pop_back(t_deque *deque)
{
	if (!deque || deque_empty(deque))
		return ;
	deque->tail = (deque->tail + 1) % deque->limit;
}
