/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:05:03 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/21 16:27:05 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static int is_integer(char *str)
{
	if (str == NULL || *str == '\0')
		return (ERROR);
	if (*str == '-')
		return (ERROR);
	while (*str != '\0')
	{
		if (!('0' <= *str && *str <= '9'))
			return (ERROR);
		str++;
	}
	return (SUCCESS);
}

int	get_args(int argc, char **argv, t_args_info *args_info)
{
	(void) argv;
	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (ERROR);
	}
	if (is_integer(argv[1]) == ERROR || is_integer(argv[2]) == ERROR || \
		is_integer(argv[3]) == ERROR || is_integer(argv[4]) == ERROR || \
		(argc == 6 && is_integer(argv[5]) == ERROR))
	{
		printf("Error: Wrong type of arguments\n");
		return (ERROR);
	}
	args_info->num_of_philo = ft_atoi(argv[1]);
	args_info->time_to_die = ft_atoi(argv[2]);
	args_info->time_to_eat = ft_atoi(argv[3]);
	args_info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args_info->num_of_must_eat = ft_atoi(argv[5]);
	else
		args_info->num_of_must_eat = 0;
	return (SUCCESS);
}
