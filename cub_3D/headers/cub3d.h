/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:56:19 by hyojocho          #+#    #+#             */
/*   Updated: 2023/07/08 17:26:05 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "structures.h"
# include "../libft/libft.h"

enum e_cub3d_enum
{
	SUCCESS = 1,
	ERROR = -1,
	FALSE = 0,
	TRUE = 1
};

enum e_side_type_enum
{
	NO = 1,
	SO = 2,
	WE = 3,
	EA = 4,
	S = 5,
	F = 6,
	C = 7,
};

enum e_check_type_enum
{
	MAP = 8,
	EMPTY_LINE = 9,
	SIDE_TEXTURE = 11,
	RGB = 12
};

// parsing
void	parse_cub_file(char *cub_file);

// error
void	validate_args(int argc);
int		validate_cube_file(char *cub_file);

// initailize
void	initialize(t_map *map, t_parse_info *parse_info);

// line_vlidation
int		check_type(char *line);
int		validate_texture(char *tex_line, t_map *map_info, t_parse_info *parse_info);
int		validate_rgb(char *tex_line, t_map *map_info, t_parse_info *parse_info);
int		validate_map(char *line, t_map *map_info, t_parse_info *parse_info);
int		validate_all_lines(t_parse_info *parse_info);

// map_validation
void	valid_map_characters(char *line, t_map *map_info, t_parse_info *parse_info);

// utils
void	print_error(char *str);
int		check_line_empty(char *line);



#endif