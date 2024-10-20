/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_lower_bound_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:49:18 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 14:17:34 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_bonus.h"

int	lower_bound(int *arr, int size, int target)
{
	int	left;
	int	right;
	int	mid;

	left = -1;
	right = size;
	while (right - left > 1)
	{
		mid = (left + right) / 2;
		if (arr[mid] >= target)
			right = mid;
		else
			left = mid;
	}
	return (right);
}
