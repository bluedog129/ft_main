/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:37:50 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/30 16:05:47 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

enum e_pipex_enum
{
	SUCCESS = 1,
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
	int		input_fd;
	int		output_fd;
	int		prev_fd;
	int		command_count;
	int		argc;
}	t_arg;

// main
void	apply_pipe(t_arg *arg);
int		set_commands(t_arg *arg, int commands_idx);
// file_open
int		open_input_file(t_arg *arg);
int		open_output_file(t_arg *arg);
// process
void	child_process(t_arg *arg, int pipe_fd[2], int index);
void	parent_process(t_arg *arg, int pipe_fd[2]);
// utils
void	free_str_array(char **str_array);
void	free_arg(t_arg *arg);

#endif