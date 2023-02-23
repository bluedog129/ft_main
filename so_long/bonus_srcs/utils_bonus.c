/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:39:11 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/23 19:49:33 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_exit(char *msg)
{
	int	len;

	len = 0;
	while (msg[len])
		len++;
	write(2, msg, len);
	exit(0);
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

void	finish_game(t_game *map_info)
{
	free_array(map_info->map, map_info->height);
	free(map_info);
	exit(0);
}
