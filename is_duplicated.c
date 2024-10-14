/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicated.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:51:58 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/14 15:57:34 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicated(int *arr, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (arr[i - 1] == arr[i])
			return (TRUE);
	return (FALSE);
}
