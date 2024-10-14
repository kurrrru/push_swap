/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:48:18 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/14 22:14:29 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lis_dp(int *arr, int size, int *dp, int *idx);
static int	*lis_traceback(int *arr, int size, int *idx, int lis_size);

int	*lis(int *arr, int size, int *lis_size)
{
	int	*dp;
	int	*idx;
	int	*ans;

	dp = (int *)malloc(sizeof(int) * size);
	idx = (int *)malloc(sizeof(int) * size);
	if (dp == NULL || idx == NULL)
		error();
	lis_dp(arr, size, dp, idx);
	*lis_size = lower_bound(dp, size, INF);
	ans = lis_traceback(arr, size, idx, *lis_size);
	return (free(dp), free(idx), ans);
}

static void	lis_dp(int *arr, int size, int *dp, int *idx)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		dp[i] = INF;
		idx[i] = -1;
	}
	i = 0;
	while (++i < size)
	{
		idx[i] = lower_bound(dp, size, arr[i]);
		dp[idx[i]] = arr[i];
	}
}

static int	*lis_traceback(int *arr, int size, int *idx, int lis_size)
{
	int	*ans;
	int	i;
	int	j;

	ans = (int *)malloc(sizeof(int) * lis_size);
	if (ans == NULL)
		error();
	i = lis_size;
	j = size;
	while (--j >= 0)
		if (idx[j] == i - 1)
			ans[--i] = arr[j];
	return (ans);
}
