/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:15:46 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/29 20:40:42 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void create_pipe(int *fd)
{
	// 1. Create a pipe
	if (pipe(fd) < 0)
	{
		perror("ERROR: Failed to create a pipe\n");
		exit(EXIT_FAILURE);
	}
	// 2. Check if the pipe is created successfully
	if (fd[0] < 0 || fd[1] < 0)
	{
		perror("ERROR: Failed to create a pipe\n");
		exit(EXIT_FAILURE);
	}
}

void	apply_pipe(t_arg *arg)
{
	int	pipe_fd[2];
	int pid;
	int index;
	
	index = 0;
	while (index < arg->command_count)
	{
		if (set_commands(arg, index) == ERROR)
			continue;
		create_pipe(pipe_fd);
		pid = fork();
		// 1. Check if the fork is created successfully
		if (pid == -1)
		{
			perror("ERROR: Failed to create a fork\n");
			exit(EXIT_FAILURE);
		}
		// 2. child process
		else if (pid == 0)
			child_process(arg, pipe_fd, index);
		// 3. parent process
		else
			parent_process(arg, pipe_fd);
		index++;
	}
	index = 0;
	while (index++ < arg->command_count)
		waitpid(-1, NULL, 0);
}