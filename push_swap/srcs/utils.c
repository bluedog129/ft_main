/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:03:38 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/04 12:40:11 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *str)
{
	int str_len;

	str_len = ft_strlen(str);
	write(2, str, str_len);
}

void	free_deque(t_deque	*deque)
{
	free(deque->arr);
	free(deque);
}
