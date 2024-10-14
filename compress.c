/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:49:53 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/14 21:49:41 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_sort(int *arr, int left, int right);
static void	swap(int *a, int *b);

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

	if (left >= right)
		return ;
	swap(&arr[left], &arr[(left + right) / 2]);
	pivot = arr[left];
	i = left + 1;
	j = right;
	while (1)
	{
		while (arr[i] < pivot)
			i++;
		while (pivot < arr[j])
			j--;
		if (i >= j)
			break ;
		swap(&arr[i], &arr[j]);
		i++;
		j--;
	}
	swap(&arr[left], &arr[j]);
	quick_sort(arr, left, i - 1);
	quick_sort(arr, j + 1, right);
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
