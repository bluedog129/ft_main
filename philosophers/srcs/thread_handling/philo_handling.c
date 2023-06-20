/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:15:38 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/20 12:40:26 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

void	*philo_routine(void *args)
{
	t_philosoper	*philosopher;

	philosopher = (t_philosoper *)args;
	while (TRUE)
	{
		if (eating(philosopher) != 0)
			return (NULL);
		sleeping(philosopher);
		thinking(philosopher);
		if (has_anyone_died(philosopher) == TRUE)
			return (NULL);
		usleep(philosopher->args_info.time_to_eat / 10);
		if (philosopher->args_info.num_of_must_eat != -1)
			usleep(philosopher->args_info.time_to_eat / 10);
	}
	return (NULL);
}
