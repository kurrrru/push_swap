/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_swap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:21:48 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 23:21:49 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_swap_front(t_deque *deque)
{
	int	front1;
	int	front2;

	if (!deque || deque_size(deque) < 2)
		return ;
	front1 = deque_at_from_front(deque, 0);
	front2 = deque_at_from_front(deque, 1);
	deque_pop_front(deque);
	deque_pop_front(deque);
	deque_push_front(deque, front1);
	deque_push_front(deque, front2);
}
