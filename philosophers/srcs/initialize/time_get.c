/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:19:39 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/21 18:58:33 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

void	time_lapse(unsigned int time)
{
	unsigned int	start_time;

	start_time = get_time();
	while (get_time() < start_time + (unsigned int)time)
	{
		usleep(100);
	}
}

unsigned int	get_time(void)
{
	struct timeval	current_time;
	unsigned int	time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
	return (time);
}

int	init_time(t_args_info *args_info)
{
	args_info->start_time = get_time();
	if ((int)args_info->start_time == ERROR)
	{
		printf("Error: Failed to get start time.\n");
		return (ERROR);
	}
	return (SUCCESS);
}
