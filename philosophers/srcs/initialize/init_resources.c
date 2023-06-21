/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:04:05 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/21 17:13:38 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static int	init_mutexes(t_resources *resources, t_args_info *args_info)
{
	unsigned int	i;

	i = 0;
	while (i < args_info->num_of_philo)
	{
		if (pthread_mutex_init(&resources->forks[i], NULL) != 0)
			return (ERROR);
		i++;
	}
	if (pthread_mutex_init(&resources->print_mutex, NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&resources->last_meal_time, NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&resources->full, NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&resources->alive, NULL) != 0)
		return (ERROR);
	return (SUCCESS);
}

int	init_resources(t_resources *resources, t_args_info *args_info)
{
	if (init_time(args_info) == ERROR)
		return (ERROR);
	resources->forks = ft_calloc(sizeof(pthread_mutex_t), args_info->num_of_philo);
	if (resources->forks == NULL)
	{
		printf("Error: Failed to calloc forks.\n");
		return (ERROR);
	}
	if (init_mutexes(resources, args_info) == ERROR)
	{
		printf("Error: Failed to init mutexes.\n");
		return (ERROR);
	}
	resources->forks_status = ft_calloc(sizeof(int), args_info->num_of_philo);
	if (resources->forks_status == NULL)
	{
		printf("Error: Failed to calloc forks_status.\n");
		return (ERROR);
	}
	resources->live = TRUE;
	resources->full_count = 0;
	return (SUCCESS);
}