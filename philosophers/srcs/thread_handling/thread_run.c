/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:58:12 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/29 18:32:40 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static int	run_odd_philo(t_philosopher *philosoper, t_args_info *args_info)
{
	unsigned int	i;

	i = 1;
	while (i < args_info->num_of_philo)
	{
		if (i & 1)
		{
			if (pthread_create(&(philosoper[i].threads), NULL, philo_routine, \
								&philosoper[i]) != 0)
			{
				printf("Fail to create %dphilo thread\n", i + 1);
				return (ERROR);
			}
		}
		i += 2;
	}
	return (SUCCESS);
}

static int	run_even_philo(t_philosopher *philosoper, t_args_info *args_info)
{
	unsigned int	i;

	i = 0;
	while (i < args_info->num_of_philo)
	{
		if (i % 2 == 0)
		{
			if (pthread_create(&(philosoper[i].threads), NULL, philo_routine, \
								&philosoper[i]) != 0)
			{
				printf("Fail to create %dphilo thread\n", i + 1);
				return (ERROR);
			}
		}
		i += 2;
	}
	return (SUCCESS);
}

int	run_threads(t_args_info *args_info, t_philosopher *philosoper)
{
	if (run_odd_philo(philosoper, args_info) == ERROR)
		return (ERROR);
	if (run_even_philo(philosoper, args_info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
