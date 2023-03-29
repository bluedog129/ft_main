/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:22:15 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/29 20:41:31 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_arg *arg, int pipe_fd[2], int index)
{
	// 1. first command
	if (index == 0 && arg->command_count > 1)
	{
		if (open_input_file(arg) == ERROR)
		{
			perror("ERROR : Not opened input file");
			exit(0);
		}
		dup2(arg->input_fd, STDIN_FILENO);
		close(arg->input_fd);//
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		execve(arg->full_path, arg->current_command, NULL);
	}
	// 2. middle command
	else if (index > 0 && index < arg->command_count - 1)
	{
		dup2(arg->prev_fd, STDIN_FILENO);
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		execve(arg->full_path, arg->current_command, NULL);
	}
	// 3. final command
	if (index == arg->command_count - 1)
	{
		if (index == 0)
		{
			if (open_input_file(arg) == ERROR)
			{
				perror("ERROR : Not opened input file");
				exit(0);
			}
			dup2(arg->input_fd, STDIN_FILENO);
			close(arg->input_fd);
		}
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		dup2(arg->prev_fd, STDIN_FILENO);
		close(arg->prev_fd);
		if (open_output_file(arg) == ERROR)
		{
			perror("ERROR : Not opened output file");
			exit(0);
		}
		dup2(arg->output_fd, STDOUT_FILENO);
		close(arg->output_fd);
		execve(arg->full_path, arg->current_command, NULL);
	}
}
