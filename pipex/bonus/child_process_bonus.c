/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:22:15 by hyojocho          #+#    #+#             */
/*   Updated: 2023/04/02 16:25:56 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	first_command(t_arg *arg, int pipe_fd[2])
{
	if (arg->here_doc == 1)
	{
		dup2(arg->tmp_fd, STDIN_FILENO);
		close(arg->tmp_fd);
	}
	else if (arg->infile_str != NULL)
	{
		if (open_input_file(arg) == ERROR)
			open_error_exit("ERROR : Not opened input file");
		dup2(arg->input_fd, STDIN_FILENO);
		close(arg->input_fd);
	}
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execve(arg->full_path, arg->current_command, NULL);
}

static void	middle_command(t_arg *arg, int pipe_fd[2])
{
	dup2(arg->prev_fd, STDIN_FILENO);
	close(arg->prev_fd);
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execve(arg->full_path, arg->current_command, NULL);
}

static void	apply_first_in_last(t_arg *arg)
{
	if (arg->here_doc == 1)
	{
		dup2(arg->tmp_fd, STDIN_FILENO);
		close(arg->tmp_fd);
	}
	else if (arg->infile_str != NULL)
	{
		if (open_input_file(arg) == ERROR)
			open_error_exit("ERROR : Not opened input file");
		dup2(arg->input_fd, STDIN_FILENO);
		close(arg->input_fd);
	}
}

static void	last_command(t_arg *arg, int pipe_fd[2], int index)
{
	if (index == 0)
		apply_first_in_last(arg);
	else
	{
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		dup2(arg->prev_fd, STDIN_FILENO);
		close(arg->prev_fd);
	}
	if (arg->here_doc == 1)
	{
		if (open_heredoc_output_file(arg) == ERROR)
			open_error_exit("ERROR: Not opened here_doc output file\n");
	}
	else
	{
		if (open_output_file(arg) == ERROR)
			open_error_exit("ERROR: Not opened output file\n");
	}
	dup2(arg->output_fd, STDOUT_FILENO);
	close(arg->output_fd);
	execve(arg->full_path, arg->current_command, NULL);
}

void	child_process(t_arg *arg, int pipe_fd[2], int index)
{
	if (set_commands(arg, index) == ERROR)
		exit(1);
	if (index == 0 && arg->command_count > 1)
		first_command(arg, pipe_fd);
	else if (index > 0 && index < arg->command_count - 1)
		middle_command(arg, pipe_fd);
	if (index == arg->command_count - 1)
		last_command(arg, pipe_fd, index);
}
