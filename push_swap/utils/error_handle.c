/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:01:13 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/15 18:01:14 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_return(char *message, int return_value)
{
	ft_putstr_fd(message, STDERR_FILENO);
	return (return_value);
}

void	free_two_dementional_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
