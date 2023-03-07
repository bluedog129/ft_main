/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:02:41 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/04 15:58:41 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_deque	*create_deque(int capacity)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	deque->capacity = capacity;
	deque->front = -1;
	deque->rear = 0;
	deque->arr = (int *)malloc(capacity * sizeof(int));
	ft_memset(deque->arr, 0, capacity);
	return (deque);
}

int	is_full(t_deque *deque)
{
	return ((deque->front == 0 && deque->rear == deque->capacity - 1) || \
			deque->front == deque->rear + 1);
}

int	is_empty(t_deque *deque)
{
	return (deque->front == -1);
}

void	push_front(t_deque *deque, int item)
{
	if (is_full(deque))
	{
		ft_printf("Deque is full\n");
		return ;
	}
	if (deque->front == -1)
	{
		deque->front = 0;
		deque->rear = 0;
	}
	else if (deque->front == 0)
		deque->front = deque->capacity - 1;
	else
		deque->front--;
	deque->arr[deque->front] = item;
}

void	push_back(t_deque *deque, int item)
{
	if (is_full(deque))
	{
		ft_printf("Deque is full\n");
		return ;
	}
	if (deque->front == -1)
	{
		deque->front = 0;
		deque->rear = 0;
	}
	else if (deque->rear == deque->capacity - 1)
		deque->rear = 0;
	else
		deque->rear++;
	deque->arr[deque->rear] = item;
}
