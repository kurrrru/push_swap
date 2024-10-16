/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:58:26 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/13 12:01:03 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_rotate_front(t_deque *deque)
{
	int	front;

	if (!deque || deque_empty(deque))
		return ;
	front = deque_front(deque);
	deque_pop_front(deque);
	deque_push_back(deque, front);
}

void	deque_rotate_back(t_deque *deque)
{
	int	back;

	if (!deque || deque_empty(deque))
		return ;
	back = deque_back(deque);
	deque_pop_back(deque);
	deque_push_front(deque, back);
}
