/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:23:00 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/01 21:35:52 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_deque	*set_dequeue(char **av)
{
	t_deque	*deque;
	int		args_num;
	int		index;

	index = 1;
	while (av[index])
		index++;
	deque = create_deque(index);
	index = 1;
	while (av[index])
	{
		args_num = (ft_atoi(av[index]));
		push_back(deque, args_num);
		index++;
	}
	return (deque);
}

void	push_swap(char **av)
{
	t_deque	*deque;
	
	deque = set_dequeue(av);
	print_deque(deque);
	free(deque);
}
