/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:02:33 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/28 22:35:46 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEUE_H
# define DEQUEUE_H

typedef struct s_deque
{
	int	capacity;
	int	front;
	int	rear;
	int	*arr;
}	t_deque;

t_deque	*create_deque(int capacity);
int		is_full(t_deque *deque);
int		is_empty(t_deque *deque);
void	push_front(t_deque *deque, int item);
void	push_back(t_deque *deque, int item);
int		pop_front(t_deque *deque);
int		pop_back(t_deque *deque);
void	print_deque(t_deque *deque);

#endif