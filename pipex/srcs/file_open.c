/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:53:11 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/23 19:17:10 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(t_arg *arg, char **argv)
{
	arg->input_fd = open(argv[1], O_RDONLY);
	if (arg->input_fd == -1)
		return (ERROR);
	arg->output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (arg->output_fd == -1)
		return (ERROR);
	return (SUCCESS);
}
// 1. Check if the file is opened successfully
// 2. Check if the file is empty
// 3. Check if the file is valid
// 4. Check if the file is closed successfully