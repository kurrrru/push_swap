/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_basic_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:43:09 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/20 13:45:20 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CH_BASIC_BONUS_H
# define CH_BASIC_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0
# define FAILURE -1
# define SUCCESS 0
# define ERROR -1

# define MSG_ERROR "Error"
# define MSG_OK "OK"
# define MSG_KO "KO"

// ch_error_bonus.c
void	error(void);

#endif