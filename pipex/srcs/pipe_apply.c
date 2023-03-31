/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:15:46 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/30 16:15:58 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	create_pipe(int *fd)
{
	if (pipe(fd) < 0)
	{
		perror("ERROR: Failed to create a pipe\n");
		exit(EXIT_FAILURE);
	}
	if (fd[0] < 0 || fd[1] < 0)
	{
		perror("ERROR: Failed to create a pipe\n");
		exit(EXIT_FAILURE);
	}
}

void	apply_pipe(t_arg *arg)
{
	int	pipe_fd[2];
	int	pid;
	int	index;

	index = 0;
	while (index < arg->command_count)
	{
		create_pipe(pipe_fd);
		pid = fork();
		if (pid == -1)
		{
			perror("ERROR: Failed to create a fork\n");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
			child_process(arg, pipe_fd, index);
		else
			parent_process(arg, pipe_fd);
		index++;
	}
	index = 0;
	while (index++ < arg->command_count)
		waitpid(-1, NULL, 0);
}
