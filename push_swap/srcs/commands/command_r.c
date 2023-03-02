/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:16:29 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/02 21:45:23 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_deque *deque)
{
	push_back(deque, pop_front(deque));
}

void	rb(t_deque *deque)
{
	push_back(deque, pop_front(deque));
}

void	rr(t_deque *deque_a, t_deque *deque_b)
{
	ra(deque_a);
	rb(deque_b);
}

void	rra(t_deque *deque)
{
	push_front(deque, pop_back(deque));
}

void	rrb(t_deque *deque)
{
	push_front(deque, pop_back(deque));
}
