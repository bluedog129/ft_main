/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:47:58 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/02 21:12:11 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_deque *deque)
{
	int	temp;

	if (is_empty(deque) || deque->front == deque->rear)
		return ;
	temp = deque->arr[deque->front];
	deque->arr[deque->front] = deque->arr[deque->front + 1];
	deque->arr[deque->front + 1] = temp;
}

void	sb(t_deque *deque)
{
	int	temp;

	if (is_empty(deque) || deque->front == deque->rear)
		return ;
	temp = deque->arr[deque->front];
	deque->arr[deque->front] = deque->arr[deque->front + 1];
	deque->arr[deque->front + 1] = temp;
}

void	ss(t_deque *deque_a, t_deque *deque_b)
{
	sa(deque_a);
	sb(deque_b);
}

void	pa(t_deque *deque_a, t_deque *deque_b)
{
	if (is_empty(deque_b))
		return ;
	push_front(deque_a, pop_front(deque_b));
}

void	pb(t_deque *deque_a, t_deque *deque_b)
{
	if (is_empty(deque_a))
		return ;
	push_front(deque_b, pop_front(deque_a));
}
