/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_is_duplicated_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:55:13 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 12:57:21 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_bonus.h"

int	is_duplicated(int *arr, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (arr[i - 1] == arr[i])
			return (TRUE);
	return (FALSE);
}
