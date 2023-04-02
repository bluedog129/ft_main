/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:53:11 by hyojocho          #+#    #+#             */
/*   Updated: 2023/04/02 16:16:48 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_input_file(t_arg *arg)
{
	arg->input_fd = open(arg->infile_str, O_RDONLY);
	if (arg->input_fd == -1)
	{
		perror("ERROR: Failed to open input_file\n");
		free_arg(arg);
		return (ERROR);
	}
	return (SUCCESS);
}

int	open_heredoc_output_file(t_arg *arg)
{
	arg->output_fd = open(arg->outfile_str, O_WRONLY | O_CREAT | O_APPEND, \
	0644);
	if (arg->output_fd == -1)
	{
		perror("ERROR: Failed to open output_file\n");
		free_arg(arg);
		return (ERROR);
	}
	return (SUCCESS);
}

int	open_output_file(t_arg *arg)
{
	arg->output_fd = open(arg->outfile_str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (arg->output_fd == -1)
	{
		perror("ERROR: Failed to open output_file\n");
		free_arg(arg);
		return (ERROR);
	}
	return (SUCCESS);
}

int	open_tmp_file(t_arg *arg)
{
	arg->tmp_fd = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (arg->tmp_fd == -1)
	{
		perror("ERROR: Failed to open tmp_file\n");
		free_arg(arg);
		return (ERROR);
	}
	return (SUCCESS);
}

void	open_error_exit(char *str)
{
	perror(str);
	exit(1);
}
