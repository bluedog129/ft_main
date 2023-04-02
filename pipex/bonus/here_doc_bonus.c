/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:09:34 by hyojocho          #+#    #+#             */
/*   Updated: 2023/04/02 15:51:01 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	get_heredoc_line(t_arg *arg)
{
	char	*line;

	write(1, "heredoc> ", 9);
	line = get_next_line(STDIN_FILENO);
	if (ft_strcmp(line, arg->limiter) == EQUAL)
	{
		free(line);
		return (FINISH);
	}
	ft_putstr_fd(line, arg->tmp_fd);
	free(line);
	return (0);
}

void	apply_heredoc(t_arg *arg)
{
	if (arg->here_doc == 0)
		return ;
	if (open_tmp_file(arg) == ERROR)
	{
		perror("ERROR: Failed to open file\n");
		return ;
	}
	while (1)
	{
		if (get_heredoc_line(arg) == FINISH)
			break ;
	}
	arg->tmp_fd = open("temp.txt", O_RDONLY);
}
