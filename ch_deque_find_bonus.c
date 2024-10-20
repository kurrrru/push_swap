/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_deque_find_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:23:29 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 12:23:30 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	deque_find(t_deque *deque, int target)
{
	int	i;

	i = -1;
	while (++i < deque_size(deque))
	{
		if (deque_at_from_front(deque, i) == target)
			return (i);
	}
	return (DEQUE_EXCEPTION_VALUE);
}
