/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:23:00 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/02 21:51:03 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_args_in_deque(t_deque	*deque, char **av)
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

static t_deque	*set_dequeue(char **av)
{
	t_deque	*deque;
	int		index;

	index = 1;
	while (av[index])
		index++;
	deque = create_deque(index);
	return (deque);
}

void	push_swap(char **av)
{
	t_deque	*deque_a;
	t_deque *deque_b;
	
	deque_a = set_dequeue(av);
	deque_b = set_dequeue(av);
	put_args_in_deque(deque_a, av);
	put_args_in_deque(deque_b, av);
	print_deque(deque_a);
	print_deque(deque_b);
	rrr(deque_a, deque_b);
	print_deque(deque_a);
	print_deque(deque_b);
}
