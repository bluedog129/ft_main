/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:27:40 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/28 22:36:03 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop_front(t_deque *deque)
{
	int	item;

	if (is_empty(deque))
	{
		ft_printf("Deque is empty\n");
		return (INT_MIN);
	}
	item = deque->arr[deque->front];
	if (deque->front == deque->rear)
	{
		deque->front = -1;
		deque->rear = -1;
	}
	else if (deque->front == deque->capacity - 1)
		deque->front = 0;
	else
		deque->front++;
	return (item);
}

int	pop_back(t_deque *deque)
{
	int	item;

	if (is_empty(deque))
	{
		ft_printf("Deque is empty\n");
		return (INT_MIN);
	}
	item = deque->arr[deque->rear];
	if (deque->front == deque->rear)
	{
		deque->front = -1;
		deque->rear = -1;
	}
	else if (deque->rear == 0)
		deque->rear = deque->capacity - 1;
	else
		deque->rear--;
	return (item);
}

void	print_deque(t_deque *deque)
{
	t_deque	*curr;

	curr = deque->head;
	while (curr != NULL)
	{
		ft_printf("%d ", curr->data);
		curr = curr->next;
	}
	ft_putchar('\n');
}
