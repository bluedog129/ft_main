/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:37:50 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/23 19:22:15 by hyojocho         ###   ########.fr       */
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
	MIN_ARGS = 5
};

typedef struct arg
{
	char 	**commands;
	char 	**paths;
	char 	**c_paths;
	int		input_fd;
	int		output_fd;
}	t_arg;

void	return_error_message(char *str);
int		set_commands(t_arg *arg, char **argv, char **envp);
void	free_str_array(char **str_array);
void	free_arg(t_arg *arg);
void	apply_pipe(t_arg *arg);
int		open_file(t_arg *arg, char **argv);


# endif