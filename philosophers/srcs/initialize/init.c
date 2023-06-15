/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:05:03 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/15 14:08:46 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

int	get_args(int argc, char **argv)
{
	(void) argv;
	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (ERROR);
	}
	return (SUCCESS);
}