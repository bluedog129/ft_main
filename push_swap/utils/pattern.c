/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:00:53 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/15 18:00:55 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pattern_three_numbers(t_stack *stack)
{
	int		a;
	int		b;
	int		c;
	int		pattern;

	a = stack->top->data;
	b = stack->top->prev->data;
	c = stack->head->data;
	pattern = 0;
	if (a > b && b > c && a > c)
		pattern = 1;
	else if (a > b && b < c && a > c)
		pattern = 2;
	else if (a < b && b > c && a > c)
		pattern = 3;
	else if (a < b && b > c && a < c)
		pattern = 4;
	else if (a > b && b < c && a < c)
		pattern = 5;
	else
		pattern = 6;
	return (pattern);
}

int	pattern_four_numbers(t_stack *stack)
{
	int		a;
	int		b;
	int		c;
	int		d;
	int		pattern;

	a = stack->top->data;
	b = stack->top->prev->data;
	c = stack->head->next->data;
	d = stack->head->data;
	pattern = 0;
	if (a < b && b < c && c > a)
		pattern = 1;
	return (pattern);
}
