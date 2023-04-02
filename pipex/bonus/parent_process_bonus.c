/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:26:09 by hyojocho          #+#    #+#             */
/*   Updated: 2023/04/02 15:23:08 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parent_process(t_arg *arg, int pipe_fd[2])
{
	close(arg->prev_fd);
	close(pipe_fd[1]);
	arg->prev_fd = pipe_fd[0];
}
