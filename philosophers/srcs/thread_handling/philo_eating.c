/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:19:50 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/22 13:00:03 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static int take_forks(t_philosopher *philo)
{
	if (philo->id & 1)
	{
		pthread_mutex_lock(&philo->resources->forks[philo->left_fork]);
		philo->resources->forks_status[philo->left_fork] = 1;
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->resources->forks[philo->right_fork]);
		philo->resources->forks_status[philo->right_fork] = 1;
		print_state(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->resources->forks[philo->right_fork]);
		philo->resources->forks_status[philo->right_fork] = 1;
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->resources->forks[philo->left_fork]);
		philo->resources->forks_status[philo->left_fork] = 1;
		print_state(philo, "has taken a fork");
	}
	return (0);
}

static void update_last_meal_time(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->resources->last_meal_time);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->resources->last_meal_time);
}

static void	put_down_forks(t_philosopher *philo)
{
	if (philo->id & 1)
	{
		philo->resources->forks_status[philo->left_fork] = 0;
		pthread_mutex_unlock(&philo->resources->forks[philo->left_fork]);
		philo->resources->forks_status[philo->right_fork] = 0;
		pthread_mutex_unlock(&philo->resources->forks[philo->right_fork]);
	}
	else
	{
		philo->resources->forks_status[philo->right_fork] = 0;
		pthread_mutex_unlock(&philo->resources->forks[philo->right_fork]);
		philo->resources->forks_status[philo->left_fork] = 0;
		pthread_mutex_unlock(&philo->resources->forks[philo->left_fork]);
	}
}

static int start_eating(t_philosopher *philo)
{
	print_state(philo, "is eating");
	time_lapse(philo->args_info.time_to_eat);
	if (philo->args_info.num_of_must_eat != 0)
	{
		philo->eat_count++;
		if (philo->eat_count == philo->args_info.num_of_must_eat)
		{
			pthread_mutex_lock(&philo->resources->full);
			philo->resources->full_count++;
			pthread_mutex_unlock(&philo->resources->full);
			put_down_forks(philo);
			return (IS_FULL);
		}
	}
	return (FALSE);
}

int	eating(t_philosopher *philosoper)
{
	int	error;

	error = TRUE;
	if (take_forks(philosoper) == ERROR)
		error = 1;
	if (error == 0)
	{
		update_last_meal_time(philosoper);
		if (start_eating(philosoper) == IS_FULL)
			return (FALSE);
	}
	put_down_forks(philosoper);
	return (TRUE);
}
