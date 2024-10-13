/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:33:02 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/13 12:02:04 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stdlib.h>

# define DEQUE_DEFAULT_LIMIT 1000
# define DEQUE_EXCEPTION_VALUE -1

typedef struct s_deque
{
	int		*data;
	int		limit;
	int		head;
	int		tail;
}			t_deque;

t_deque	*deque_init();
void	deque_free(t_deque *deque);
int		deque_size(t_deque *deque);
int		deque_empty(t_deque *deque);
int		deque_front(t_deque *deque);
int		deque_back(t_deque *deque);
int		deque_at_from_front(t_deque *deque, int index);
int		deque_at_from_back(t_deque *deque, int index);
void	deque_push_front(t_deque *deque, int value);
void	deque_push_back(t_deque *deque, int value);
void	deque_pop_front(t_deque *deque);
void	deque_pop_back(t_deque *deque);
void	deque_rotate_front(t_deque *deque);
void	deque_rotate_back(t_deque *deque);
void	deque_swap_front(t_deque *deque);

#endif