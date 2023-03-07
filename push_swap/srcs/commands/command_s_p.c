/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_s_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:47:58 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/07 11:50:12 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_deque *deque)
{
	ft_printf("sa\n");
	int	temp;

	if (is_empty(deque) || deque->front == deque->rear)
		return ;
	temp = deque->arr[deque->front];
	deque->arr[deque->front] = deque->arr[deque->front + 1];
	deque->arr[deque->front + 1] = temp;
}

void	sb(t_deque *deque)
{
	ft_printf("sb\n");
	int	temp;

	if (is_empty(deque) || deque->front == deque->rear)
		return ;
	temp = deque->arr[deque->front];
	deque->arr[deque->front] = deque->arr[deque->front + 1];
	deque->arr[deque->front + 1] = temp;
}

void	ss(t_deque *deque_a, t_deque *deque_b)
{
	ft_printf("ss\n");
	sa(deque_a);
	sb(deque_b);
}

void	pa(t_deque *deque_a, t_deque *deque_b)
{
	ft_printf("pa\n");
	if (is_empty(deque_b))
		return ;
	push_front(deque_a, pop_front(deque_b));
}

void	pb(t_deque *deque_a, t_deque *deque_b)
{
	ft_printf("pb\n");
	if (is_empty(deque_a))
		return ;
	push_front(deque_b, pop_front(deque_a));
}
