/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:53:11 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/29 18:48:41 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_input_file(t_arg *arg)
{
	arg->input_fd = open(arg->infile_str, O_RDONLY);
	if (arg->input_fd == -1)
	{
		perror("ERROR: Failed to open file\n");
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
		perror("ERROR: Failed to open file\n");
		free_arg(arg);
		return (ERROR);
	}
	return (SUCCESS);
}
