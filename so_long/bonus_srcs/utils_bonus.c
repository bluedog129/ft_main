/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:56:23 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/20 15:15:03 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_error(char *msg)
{
	int	len;

	len = 0;
	while (msg[len])
		len++;
	write(2, msg, len);
}

void	print_messages(char *msg)
{
	int	len;

	len = 0;
	while (msg[len])
		len++;
	write(1, msg, len);
}

int	handle_close_button(void *param)
{
	(void)param;
	print_messages("You clicked close button!\n");
	exit(0);
}

void	free_array(char **array, int size)
{
	while (size--)
		free(array[size]);
	free(array);
}
