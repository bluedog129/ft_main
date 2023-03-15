/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:01:36 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/15 18:01:37 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack *list)
{
	int	temp;

	if (list->top && list->top->prev)
	{
		temp = list->top->data;
		list->top->data = list->top->prev->data;
		list->top->prev->data = temp;
	}
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
