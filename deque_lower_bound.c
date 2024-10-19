/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_lower_bound.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:35:35 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/19 18:15:42 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h>

int	deque_lower_bound(t_deque *deque, int target)
{
	int	left;
	int	right;
	int	mid;

	left = -1;
	right = deque_size(deque);
	while (right - left > 1)
	{
		mid = (left + right) / 2;
		if (deque_at_from_front(deque, mid) >= target)
			right = mid;
		else
			left = mid;
	}
	return (right);
}