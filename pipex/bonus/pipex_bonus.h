/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:37:50 by hyojocho          #+#    #+#             */
/*   Updated: 2023/04/02 16:20:38 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

enum e_pipex_enum
{
	SUCCESS = 1,
	EQUAL = 0,
	FINISH = 1,
	MIN_ARGS = 4
};

typedef struct arg
{
	char	**commands;
	char	**paths;
	char	**current_command;
	char	*infile_str;
	char	*outfile_str;
	char	*full_path;
	char	*limiter;
	int		input_fd;
	int		output_fd;
	int		prev_fd;
	int		tmp_fd;
	int		command_count;
	int		argc;
	int		here_doc;
}	t_arg;

// main
void	apply_pipe(t_arg *arg);
int		set_commands(t_arg *arg, int commands_idx);
// file_open
int		open_input_file(t_arg *arg);
int		open_output_file(t_arg *arg);
int		open_tmp_file(t_arg *arg);
int		open_heredoc_output_file(t_arg *arg);
void	open_error_exit(char *str);
// here_doc
void	apply_heredoc(t_arg *arg);
// process
void	child_process(t_arg *arg, int pipe_fd[2], int index);
void	parent_process(t_arg *arg, int pipe_fd[2]);
// utils
void	free_str_array(char **str_array);
void	free_arg(t_arg *arg);

#endif