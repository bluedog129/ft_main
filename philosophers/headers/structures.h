/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:37:18 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/21 20:06:35 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "../../libft/libft.h"

enum e_philosophers_enum
{
	SUCCESS = 1,
	ERROR = -1,
	FALSE = 0,
	TRUE = 1,
	IS_FULL = 2,
	FINISHED = 3
};

typedef struct s_resources
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	last_meal_time;
	pthread_mutex_t	full;
	pthread_mutex_t	alive;
	int				live;
	int				full_count;
	int				start_time;
	int				*forks_status;
}	t_resources;

typedef struct s_args_info
{
	unsigned int	num_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	num_of_must_eat;
	unsigned int	start_time;
}	t_args_info;

typedef struct s_philosopher
{
	pthread_t		threads;
	t_resources		*resources;
	t_args_info		args_info;
	unsigned int	last_meal_time;
	int				id;
	int				left_fork;
	int				right_fork;
	unsigned int	eat_count;
}	t_philosopher;

#endif