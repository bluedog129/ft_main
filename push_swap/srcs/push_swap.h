/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:23:04 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/02 21:51:27 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "./dequeue/dequeue.h"
# include <limits.h>

enum e_definition
{
	ERROR = -1,
	VALIDATE_PASS = 1
};

int		validate_args(int ac, char **av);
void	print_error(char *str);
void	push_swap(char **av);
void	sa(t_deque	*deque);
void	sb(t_deque *deque);
void	ss(t_deque *deque_a, t_deque *deque_b);
void	pa(t_deque *deque_a, t_deque *deque_b);
void	pb(t_deque *deque_a, t_deque *deque_b);
void	ra(t_deque *deque);
void	rb(t_deque *deque);
void	rr(t_deque *deque_a, t_deque *deque_b);
void	rra(t_deque *deque);
void	rrb(t_deque *deque);
void	rrr(t_deque *deque_a, t_deque *deque_b);

#endif