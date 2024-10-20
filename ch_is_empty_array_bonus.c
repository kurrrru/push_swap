/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_is_empty_array_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:55:21 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 12:57:30 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_bonus.h"

int	is_empty_array(int argc)
{
	if (argc < VALID_ARGC_MIN)
		return (TRUE);
	return (FALSE);
}
