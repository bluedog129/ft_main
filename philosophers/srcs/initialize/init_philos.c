/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:09:52 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/21 16:11:50 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

int	init_philos(t_resources *resources, t_args_info *args_info, \
				t_philosopher *philosopher)
{
	unsigned int i;

	philosopher = (t_philosopher *)ft_calloc(args_info->num_of_philo, \
											sizeof(t_philosopher));
	if (philosopher == NULL)
	{
		printf("Error: philosopher calloc failed\n");
		return (ERROR);
	}
	i = 0;
	while (i < args_info->num_of_philo)
	{
		philosopher[i].id = i + 1;
		philosopher[i].resources = resources;
		philosopher[i].args_info = *args_info;
		philosopher[i].left_fork = i;
		philosopher[i].right_fork = (i + 1) % args_info->num_of_philo;
		philosopher[i].eat_count = 0;
		philosopher[i].last_meal_time = get_time();
		i++;
	}
	return (SUCCESS);
}