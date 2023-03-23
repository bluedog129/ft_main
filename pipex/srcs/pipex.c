/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:17:39 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/23 18:05:49 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	validate_args(int argc)
{
	if (argc < MIN_ARGS)
	{
		return_error_message("ERROR : argument error\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int	main(int argc, char **argv, char **envp) 
{
	t_arg	*arg;
	
	if (validate_args(argc) == ERROR)
		return (EXIT_FAILURE);
	arg = malloc(sizeof(t_arg));
	arg->commands = malloc(sizeof(char*) * 3);
	arg->c_paths = malloc(sizeof(char*) * 3);
	if (open_file(arg, argv) == ERROR)
	{
		return_error_message("ERROR: Failed to open file\n");
		free_arg(arg);
		return (EXIT_FAILURE);
	}
	if (set_commands(arg, argv, envp) == ERROR)
	{
		return_error_message("ERROR: Failed to set commands\n");
		free_arg(arg);
		return (EXIT_FAILURE);
	}
	apply_pipe(arg);
	free_arg(arg);
    return (EXIT_SUCCESS);
}
