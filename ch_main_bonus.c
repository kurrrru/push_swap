/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:23:55 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 13:02:30 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_bonus.h"

int	main(int argc, char **argv)
{
	int	i;
	int	*input_array;
	int	result;

	if (is_empty_array(argc))
		empty_array();
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
	result = checker(input_array, argc - 1);
	if (result == TRUE)
		ft_putendl_fd(MSG_OK, STDOUT_FILENO);
	else
		ft_putendl_fd(MSG_KO, STDOUT_FILENO);
	free(input_array);
	return (SUCCESS);
}
