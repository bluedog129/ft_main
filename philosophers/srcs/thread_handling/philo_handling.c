/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:15:38 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/22 13:42:18 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static void	thinking(t_philosopher *philosopher)
{
	print_state(philosopher, "is thinking");
}

static void	sleeping(t_philosopher *philosopher)
{
	print_state(philosopher, "is sleeping");
	time_lapse(philosopher->args_info.time_to_sleep);
}

static int	has_anyone_died(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->resources->alive);
	if (philosopher->resources->live == FALSE)
	{
		pthread_mutex_unlock(&philosopher->resources->alive);
		return (TRUE);
	}
	pthread_mutex_unlock(&philosopher->resources->alive);
	return (FALSE);
}

void	*philo_routine(void *args)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)args;
	while (TRUE)
	{
		if (eating(philosopher) != TRUE)
			return (NULL);
		sleeping(philosopher);
		thinking(philosopher);
		if (has_anyone_died(philosopher) == TRUE)
			return (NULL);
		usleep(philosopher->args_info.time_to_eat / 10);
		if (philosopher->args_info.num_of_must_eat != 0)
			usleep(philosopher->args_info.time_to_eat / 10);
	}
	return (NULL);
}
