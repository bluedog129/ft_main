/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:26:09 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/30 16:11:29 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(t_arg *arg, int pipe_fd[2])
{
	close(arg->prev_fd);
	close(pipe_fd[1]);
	arg->prev_fd = pipe_fd[0];
}
