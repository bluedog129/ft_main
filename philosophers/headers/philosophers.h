/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:58:04 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/17 20:01:53 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define RED "\033[1;31m"
# define PINK "\033[1;35m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define DEFAULT "\033[0m"

# include "structures.h"

// get_args
int				get_args(int argc, char **argv, t_args_info *args_info);
unsigned int	get_time(void);
// init_resources
int				init_resources(t_resources *resources, t_args_info *args_info);
int				init_time(t_args_info *args_info);
// init_philos
int	init_philos(t_resources *resources, t_args_info *args_info, \
				t_philosoper *philosopher);

#endif