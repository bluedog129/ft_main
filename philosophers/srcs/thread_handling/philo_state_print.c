/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:38:05 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/28 14:51:08 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static int	check_philo_alive(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->resources->alive);
	if (philosopher->resources->live == FALSE)
	{
		pthread_mutex_unlock(&philosopher->resources->alive);
		return (FALSE);
	}
	pthread_mutex_unlock(&philosopher->resources->alive);
	return (TRUE);
}

static void	print_is_eating(t_philosopher *philosopher, long long time, \
							char *state)
{
	pthread_mutex_lock(&philosopher->resources->print_mutex);
	if (check_philo_alive(philosopher) == FALSE)
	{
		pthread_mutex_unlock(&philosopher->resources->print_mutex);
		return ;
	}
	printf(GREEN "%lld %d %s" DEFAULT "\n", time, philosopher->id, state);
}

static void	print_dead(t_philosopher *philosopher, long long time, \
						char *state)
{
	pthread_mutex_lock(&philosopher->resources->alive);
	philosopher->resources->live = FALSE;
	pthread_mutex_unlock(&philosopher->resources->alive);
	pthread_mutex_lock(&philosopher->resources->print_mutex);
	printf(RED "%lld %d %s" DEFAULT "\n", time, philosopher->id, state);
}

static void print_philo_state(t_philosopher *philosopher, long long time, \
								char *state)
{
	pthread_mutex_lock(&philosopher->resources->print_mutex);
	if (check_philo_alive(philosopher) == FALSE)
	{
		pthread_mutex_unlock(&philosopher->resources->print_mutex);
		return ;
	}
	printf("%lld %d %s\n", time, philosopher->id, state);
}

void	print_state(t_philosopher *philosopher, char *state)
{
	long long	time;
	long long	current_time;

	current_time = get_time();
	time = current_time - philosopher->resources->start_time;
	if (ft_strncmp(state, "is eating", 10) == 0)
	{
		print_is_eating(philosopher, time, state);
	}
	else if (ft_strncmp(state, "died", 4) == 0)
	{
		print_dead(philosopher, time, state);
	}
	else
	{
		print_philo_state(philosopher, time, state);
	}
	pthread_mutex_unlock(&philosopher->resources->print_mutex);
}
