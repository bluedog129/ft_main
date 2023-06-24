/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:19:00 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/24 15:29:07 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static void	destroy_mutexes(t_resources *resources, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		pthread_mutex_destroy(&resources->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&resources->print_mutex);
	pthread_mutex_destroy(&resources->last_meal_time);
	pthread_mutex_destroy(&resources->full);
	pthread_mutex_destroy(&resources->alive);
}

static void	free_memory(t_philosopher **philosopher, t_resources *resources)
{
	free(resources->forks_status);
	free(resources->forks);
	free(*philosopher);
	*philosopher = NULL;
}

static void	join_threads(t_philosopher **philosopher)
{
	unsigned int		i;
	t_args_info			*args_info;

	args_info = &((*philosopher)[0].args_info);
	i = 0;
	while (i < args_info->num_of_philo)
	{
		pthread_join((*philosopher)[i].threads, NULL);
		i++;
	}
}

void	finish_simulation(t_philosopher **philosopher)
{
	t_args_info		*args_info;
	t_resources		*resources;

	args_info = &((*philosopher)[0].args_info);
	resources = (*philosopher)[0].resources;
	if (args_info->num_of_philo == 1)
	{
		pthread_detach((*philosopher)[0].threads);
		destroy_mutexes(resources, args_info->num_of_philo);
		free_memory(philosopher, resources);
		return ;
	}
	join_threads(philosopher);
	destroy_mutexes(resources, args_info->num_of_philo);
	free_memory(philosopher, resources);
}
