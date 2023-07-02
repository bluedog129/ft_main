/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:11:26 by hyojocho          #+#    #+#             */
/*   Updated: 2023/07/02 15:41:04 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static int	is_everyone_full(t_philosopher *philosopher)
{
	if (philosopher->args_info.num_of_must_eat < 1)
		return (FALSE);
	pthread_mutex_lock(&(philosopher)->resources->full);
	if (philosopher->resources->full_count == \
		philosopher->args_info.num_of_philo)
	{
		pthread_mutex_unlock(&(philosopher)->resources->full);
		return (TRUE);
	}
	pthread_mutex_unlock(&(philosopher)->resources->full);
	return (FALSE);
}

static int	is_philo_dead(t_philosopher *philosopher)
{
	unsigned int	current_time;
	unsigned int	time_since_last_meal;

	current_time = get_time();
	pthread_mutex_lock(&(philosopher)->resources->last_meal_time);
	time_since_last_meal = current_time - philosopher->last_meal_time;
	pthread_mutex_unlock(&(philosopher)->resources->last_meal_time);
	if (time_since_last_meal >= philosopher->args_info.time_to_die)
		return (TRUE);
	return (FALSE);
}

static int	check_philo_state(t_philosopher *philosopher)
{
	if (is_everyone_full(philosopher))
		return (FINISHED);
	if (is_philo_dead(philosopher))
	{
		print_state(philosopher, "died");
		return (FINISHED);
	}
	return (FALSE);
}

void	run_monitor(t_philosopher *philosopher)
{
	unsigned int	i;
	t_args_info		*args_info;

	args_info = &(philosopher[0].args_info);
	while (1)
	{
		i = 0;
		while (i < args_info->num_of_philo)
		{
			if (check_philo_state(&philosopher[i]) == FINISHED)
				return ;
			i++;
		}
		usleep(500);
	}
}
