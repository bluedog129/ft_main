/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:54:48 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/28 18:54:43 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	validate_commands(t_arg *arg, int commands_idx)
{
	char	**commands_info;
	char	*temp_path;
	int		paths_idx;

	paths_idx = 0;
	while (arg->paths[paths_idx])
	{
		commands_info = ft_split(arg->commands[commands_idx], ' ');
		temp_path = ft_strjoin(arg->paths[paths_idx], "/");
		arg->full_path = ft_strjoin(temp_path, commands_info[0]);
		free(temp_path);
		if (access(arg->full_path, X_OK) == 0)
			return (SUCCESS);
		paths_idx++;
	}
	free_str_array(commands_info);
	return (ERROR);
}

static void	make_curr_command_info(t_arg *arg, int commands_idx)
{
	arg->current_command = ft_split(arg->commands[commands_idx], ' ');
}

int	set_commands(t_arg *arg, int commands_idx)
{
	if (arg->paths == NULL)
    {
        perror("ERROR: PATH not set in environment variables\n");
        return (ERROR);
    }
	if (arg->commands == NULL)
	{
		perror("ERROR: commands are invalid\n");
		return (ERROR);
	}
	(void)commands_idx;
	if (validate_commands(arg, commands_idx) == ERROR)
	{
		perror("ERROR: commands not found\n");
		return (ERROR);
	}
	make_curr_command_info(arg, commands_idx);
	return (SUCCESS);
}
