/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:48:22 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/14 14:48:56 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	*input_array;

	if (is_empty_array(argc))
		return (SUCCESS);
	i = 0;
	while (++i < argc)
		if (!is_valid_string(argv[i]))
			error();
	input_array = (int *)malloc(sizeof(int) * (argc - 1));
	if (input_array == NULL)
		error();
	i = 0;
	while (++i < argc)
		input_array[i - 1] = ft_atoi(argv[i]);
	push_swap(input_array, argc - 1);
	free(input_array);
	return (SUCCESS);
}
