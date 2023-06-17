/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:37:18 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/17 17:48:31 by hyojocho         ###   ########.fr       */
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
	TRUE = 1
};

typedef struct s_resources
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	last_meal_time;
	pthread_mutex_t	full;
	pthread_mutex_t	living;
	int				full_count;
	int				live;
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


#endif