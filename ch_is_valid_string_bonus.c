/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_is_valid_string_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:55:27 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 14:38:42 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_bonus.h"

static int	ft_isspace(char c);
static int	ft_isnull(char c);

int	is_valid_string(const char *str)
{
	int		i;
	long	sign;
	long	num;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	if (!ft_isdigit(str[i]))
		return (FALSE);
	num = 0;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i++] - '0') * sign;
		if (num > INT_MAX || num < INT_MIN)
			return (FALSE);
	}
	if (ft_isnull(str[i]))
		return (TRUE);
	return (FALSE);
}

static int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

static int	ft_isnull(char c)
{
	return (c == '\0');
}
