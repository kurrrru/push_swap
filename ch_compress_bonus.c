/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_compress_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:24:59 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 12:50:33 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_bonus.h"
#include <stdio.h>

static void	quick_sort(int *arr, int left, int right);
static void	ft_swap(int *a, int *b);

void	compress(int *arr, int size)
{
	int	*arr_sorted;
	int	i;

	arr_sorted = (int *)malloc(sizeof(int) * size);
	if (arr_sorted == NULL)
		error();
	i = -1;
	while (++i < size)
		arr_sorted[i] = arr[i];
	quick_sort(arr_sorted, 0, size);
	if (is_duplicated(arr_sorted, size))
		error();
	i = -1;
	while (++i < size)
		arr[i] = lower_bound(arr_sorted, size, arr[i]);
	free(arr_sorted);
}

static void	quick_sort(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	if (left + 1 >= right)
		return ;
	ft_swap(&arr[left], &arr[(left + right) / 2]);
	pivot = arr[left];
	i = left + 1;
	j = right - 1;
	while (1)
	{
		while (i < right && arr[i] <= pivot)
			i++;
		while (left <= j && pivot < arr[j])
			j--;
		if (i >= j)
			break ;
		ft_swap(&arr[i], &arr[j]);
	}
	if (left < j)
		ft_swap(&arr[left], &arr[j]);
	quick_sort(arr, left, j);
	quick_sort(arr, j + 1, right);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
