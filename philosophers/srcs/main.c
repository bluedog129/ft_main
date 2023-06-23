/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:20:26 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/23 17:13:29 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

int	main(int argc, char **argv)
{
	t_args_info		args_info;
	t_resources		resources;
	t_philosopher	*philosopher;

	if (get_args(argc, argv, &args_info) == ERROR)
		return (ERROR);
	if (init_resources(&resources, &args_info) == ERROR)
		return (ERROR);
	if (init_philos(&resources, &args_info, &philosopher) == ERROR)
		return (ERROR);
	if (run_threads(&args_info, philosopher) == ERROR)
		return (ERROR);
	run_monitor(philosopher);
	// if (wait_threads(&resources, &args_info) == ERROR)
	// 	return (ERROR);
	return (SUCCESS);
}