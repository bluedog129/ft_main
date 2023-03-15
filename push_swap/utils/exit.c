/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:01:08 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/15 18:01:09 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	destroy_stacks_and_exit(t_stack *stack_a, \
		t_stack *stack_b, int exit_status)
{
	destroy_stack(&stack_a);
	destroy_stack(&stack_b);
	exit(exit_status);
}

void	error_exit(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Error\n");
	if (stack_a != NULL)
		destroy_stack(&stack_a);
	if (stack_b != NULL)
		destroy_stack(&stack_b);
	exit(EXIT_FAILURE);
}
