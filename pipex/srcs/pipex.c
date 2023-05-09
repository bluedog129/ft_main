/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:17:39 by hyojocho          #+#    #+#             */
/*   Updated: 2023/05/04 21:07:12 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	validate_args(int argc)
{
	if (argc != 5)
	{
		perror("ERROR : argument error\n");
		return (ERROR);
	}
	return (SUCCESS);
}

static char	**get_commands(t_arg *arg, char **argv)
{
	int		arg_idx;
	int		commands_idx;
	char	**commands;

	arg_idx = 2;
	while (argv[arg_idx])
		arg_idx++;
	arg->command_count = arg_idx - 3;
	commands = (char **)malloc(sizeof(char *) * (arg->command_count + 1));
	commands_idx = 0;
	while (commands_idx < arg->command_count)
	{
		commands[commands_idx] = ft_strdup(argv[commands_idx + 2]);
		commands_idx++;
	}
	commands[commands_idx] = NULL;
	return (commands);
}

static char	**get_paths(char **envp)
{
	while (*envp != NULL && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (*envp == NULL)
	{
		perror("ERROR: Failed to get PATH\n");
		return (NULL);
	}
	return (ft_split(*envp + 5, ':'));
}

static void	initialize_structs(int argc, char **argv, char **envp, t_arg *arg)
{
	arg->commands = get_commands(arg, argv);
	arg->paths = get_paths(envp);
	arg->argc = argc;
	arg->infile_str = argv[1];
	arg->outfile_str = argv[argc - 1];
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	*arg;

	if (validate_args(argc) == ERROR)
		return (EXIT_FAILURE);
	arg = malloc(sizeof(t_arg));
	initialize_structs(argc, argv, envp, arg);
	apply_pipe(arg);
	free_arg(arg);
	return (EXIT_SUCCESS);
}
