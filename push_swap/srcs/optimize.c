/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:37:46 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/07 21:25:41 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_three_lefted_elements(t_deque *deque_a, int a, int b, int c)
{
	int	*deque;

	deque = deque_a->arr;
	if (deque[a] < deque[b] && deque[b] < deque[c])
		return ;
	else if (deque[a] > deque[b] && deque[b] < deque[c] && deque[a] < deque[c])
		sa(deque_a);
	else if (deque[a] < deque[b] && deque[b] > deque[c] && deque[a] < deque[c])
	{
		sa(deque_a);
		ra(deque_a);
	}
	else if (deque[a] < deque[b] && deque[b] > deque[c] && deque[a] > deque[c])
	{
		ra(deque_a);
		ra(deque_a);
	}
	else if (deque[a] > deque[b] && deque[b] < deque[c] && deque[a] > deque[c])
		ra(deque_a);
	else if (deque[a] > deque[b] && deque[b] > deque[c])
	{
		sa(deque_a);
		rra(deque_a);
	}
}

void	optimize_two_elements(t_deque *deque_a)
{
	if (deque_a->arr[deque_a->front] > deque_a->arr[deque_a->front + 1])
		ra(deque_a);
}
