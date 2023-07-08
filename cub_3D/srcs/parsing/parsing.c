/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:28:09 by hyojocho          #+#    #+#             */
/*   Updated: 2023/07/08 17:12:44 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static int	open_file(char *cub_file)
{
	int	fd;

	fd = open(cub_file, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	return (fd);
}


static void	parse_map(t_map *map_info, t_parse_info *parse_info)
{
	char	*line;
	int		side_type;

	while (1)
	{
 		line = get_next_line(parse_info->fd);
		if (line == NULL)
			break ;
		parse_info->line_type = check_type(line);
		if (parse_info->line_type == SIDE_TEXTURE)
			validate_texture(line, map_info, parse_info);
		else if (parse_info->line_type == RGB)
			validate_rgb(line, map_info, parse_info);
		else if (parse_info->line_type == MAP)
			validate_map(line, map_info, parse_info);
	}
	if (validate_all_lines(parse_info) == ERROR)
		exit_error("Error: invalid map validation\n", map_info, parse_info);
}

void	parse_cub_file(char *cub_file)
{
	t_map			*map_info;
	t_parse_info	*parse_info;

	if (validate_cube_file(cub_file) == ERROR)
		print_error("Error: Invalid file name\n");
	parse_info->fd = open_file(cub_file);
	if (parse_info->fd == ERROR)
		print_error("Error: Invalid file\n");
	initialize(map_info, parse_info);
	parse_map(map_info, parse_info);
	close(parse_info->fd);
}
