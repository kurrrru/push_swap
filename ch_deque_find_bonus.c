/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_deque_find_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:23:29 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 17:44:18 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_deque_bonus.h"

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
