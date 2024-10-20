/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_deque_rotate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:23:45 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 17:44:34 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_deque_bonus.h"

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
