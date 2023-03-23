/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:54:48 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/22 22:33:49 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path_envp(char **envp)
{
	char	*path;
	
	path = NULL;
    while (*envp != NULL && ft_strncmp("PATH", *envp, 4))
        envp++;
    if (*envp == NULL)
        return (NULL);
    path = *envp + 5;
    return (ft_split(path, ':'));
}

static void	check_pass_is_collect(int commands_idx, int *access_count, \
									t_arg *arg)
{
	char	**commands_info;
	char	*full_path;
	char	*temp_path;
	int		paths_idx;
	
	paths_idx = 0;
	while (arg->paths[paths_idx])
	{
		commands_info = ft_split(arg->commands[commands_idx], ' ');
		temp_path = ft_strjoin(arg->paths[paths_idx], "/");
		full_path = ft_strjoin(temp_path, commands_info[0]);
		free(temp_path);
		if (access(full_path, X_OK) == 0)
		{
			arg->c_paths[*access_count] = full_path;
			(*access_count)++;
		}
		else
			free(full_path);
		arg->c_paths[*access_count] = NULL;
		free_str_array(commands_info);
		paths_idx++;
	}
}

static int	validate_commands(t_arg *arg)
{
	int		commands_idx;
	int		access_count;
	

	commands_idx = 0;
	access_count = 0;
	while (arg->commands[commands_idx])
	{
		check_pass_is_collect(commands_idx, &access_count, arg);
		commands_idx++;
	}
	free_str_array(arg->paths);
	if (access_count == commands_idx)
		return (SUCCESS);
	return_error_message("ERROR: one or more commands are invalid\n");
	return (ERROR);
}

int	set_commands(t_arg *arg, char **argv, char **envp)
{
	arg->paths = get_path_envp(envp);
	if (arg->paths == NULL)
    {
        return_error_message("ERROR: PATH not set in environment variables\n");
        return (ERROR);
    }
	arg->commands[0] = argv[2];
	arg->commands[1] = argv[3];
	arg->commands[2] = NULL;
	if (validate_commands(arg) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
