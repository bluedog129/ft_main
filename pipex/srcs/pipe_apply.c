/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:15:46 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/23 20:14:46 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void create_pipe(int *fd)
{
	// 1. Create a pipe
	if (pipe(fd) < 0)
	{
		return_error_message("ERROR: Failed to create a pipe\n");
		exit(EXIT_FAILURE);
	}
	// 2. Check if the pipe is created successfully
	if (fd[0] < 0 || fd[1] < 0)
	{
		return_error_message("ERROR: Failed to create a pipe\n");
		exit(EXIT_FAILURE);
	}
}

void	apply_pipe(t_arg *arg)
{
	int	fd[2];
	int pid;
	char **cmd;
	// 1. Create a pipe
	create_pipe(fd);
	// 2. Fork
	pid = fork();
	// 2-1. Check if the fork is successful
	if (pid < 0)
	{
		return_error_message("ERROR: Failed to fork\n");
		exit(EXIT_FAILURE);
	}
	// 3. Child process	
	else if (pid == 0)
	{
		// 3-0 close the pipe
		close(fd[0]);
		// 3-1. Redirect the input
		if (dup2(arg->input_fd, STDIN_FILENO) < 0)
		{
			return_error_message("ERROR: Failed to redirect the input\n");
			exit(EXIT_FAILURE);
		}
		// 3-2. Redirect the output
		if (dup2(fd[1], STDOUT_FILENO) < 0)
		{     
			return_error_message("ERROR: Failed to redirect the output\n");
			exit(EXIT_FAILURE);
		}
		// 3-3. Execute the command
		cmd = ft_split(arg->commands[1], ' ');
		if (execve(arg->c_paths[1], cmd, NULL) < 0)
		{
			return_error_message("ERROR: Failed to execute the command\n");
			exit(EXIT_FAILURE);
		}
		// 3-4. Close the pipe
		close(fd[1]);
	}
	// 4. Parent process
	else
	{
		close(fd[1]);
		// 4-1. Redirect the output
		if (dup2(fd[0], STDOUT_FILENO) < 0)
		{
			return_error_message("ERROR: Failed to redirect the output\n");
			exit(EXIT_FAILURE);
		}
		if (dup2(arg->output_fd, STDOUT_FILENO) < 0)
		{
			return_error_message("ERROR: Failed to redirect the output\n");
			exit(EXIT_FAILURE);
		}
		// 4-2. Execute the command
		cmd = ft_split(arg->commands[0], ' ');
		if (execve(arg->c_paths[0], cmd, NULL) < 0)
		{
			return_error_message("ERROR: Failed to execute the command\n");
			exit(EXIT_FAILURE);
		}
		// 4-4. Wait for the child process to finish
		waitpid(pid, NULL, 0);
	}
}