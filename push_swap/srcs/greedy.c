/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:16:45 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/07 11:10:03 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_command_use(t_deque *deque_a, t_deque *deque_b, int index)
{
	int	
}

static int	get_priority_index(t_deque *deque_a, t_deque *deque_b)
{
	int	index;
	int	priority_index;
	int	command_use_count;
	int command_use_min;

	index = deque_b->front;
	command_use_min = 0;
	while (index != deque_b->rear)
	(
		command_use_count = count_command_use(deque_a, deque_b, index);
		if (command_use_min > command_use_count)
		{
			command_use_min = command_use_count;
			priority_index = index;
		}
		index++;
	)
	return (index);
}

void	apply_greedy(t_deque *deque_a, t_deque *deque_b)
{
	int	prioriy_index;

	while (!is_empty(deque_b))
	{
		prioriy_index = get_priority_index(deque_a, deque_b);
		
	}
}
