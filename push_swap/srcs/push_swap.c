/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:23:00 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/07 21:42:07 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_args_in_deque(t_deque	*deque, char **av)
{
	int		args_num;
	int		index;

	index = 1;
	while (av[index])
	{
		args_num = (ft_atoi(av[index]));
		push_back(deque, args_num);
		index++;
	}
}

static t_deque	*set_deque(char **av)
{
	t_deque	*deque;
	int		index;

	index = 1;
	while (av[index])
		index++;
	deque = create_deque(index - 1);
	return (deque);
}

static void	push_elements_a_to_b_leave_three(t_deque *deque_a, t_deque *deque_b)
{
	while(deque_a->rear - deque_a->front > 2)
	{
		pb(deque_a, deque_b);
	}
}

void	push_swap(char **av)
{
	t_deque	*deque_a;
	t_deque *deque_b;
	
	deque_a = set_deque(av);
	deque_b = set_deque(av);
	put_args_in_deque(deque_a, av);
	if (deque_a->capacity < 3)
	{
		optimize_two_elements(deque_a);
		finish_push_swap(deque_a, deque_b);
		return ;
	}
	push_elements_a_to_b_leave_three(deque_a, deque_b);
	optimize_three_lefted_elements(deque_a, deque_a->front, deque_a->front + 1,\
									 deque_a->front + 2);
	// apply_greedy(deque_a, deque_b);
	finish_push_swap(deque_a, deque_b);
}
