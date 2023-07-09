/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choihyojong <choihyojong@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:28:09 by hyojocho          #+#    #+#             */
/*   Updated: 2023/07/09 16:46:37 by choihyojong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	parse_map(t_map *map_info, t_parse_info *parse_info)
{
	char	*line;

	while (1)
	{
 		line = get_next_line(parse_info->fd);
		if (line == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		parse_info->line_type = check_type(line);
		if (parse_info->line_type == SIDE_TEXTURE)
			validate_texture(line, map_info, parse_info);
		else if (parse_info->line_type == RGB)
			validate_rgb(line, map_info, parse_info);
		else if (parse_info->line_type == MAP)
			validate_map(line, map_info, parse_info);
		else if (parse_info->line_type == EMPTY_LINE && map_info->height > 0)
			exit_error("Error: Invalid empty_line map\n", map_info, parse_info);
	}
	if (validate_all_lines(parse_info) == ERROR)
		exit_error("Error: invalid all map validation\n", map_info, parse_info);
	printf("floor_rgb : %d\n", map_info->side_info->floor_rgb);
	printf("ceiling_rgb : %d\n", map_info->side_info->ceiling_rgb);
}

void	parse_cub_file(char *cub_file)
{
	t_map			map_info;
	t_parse_info	parse_info;

	initialize(cub_file, &map_info, &parse_info);
	parse_map(&map_info, &parse_info);
	if (parse_info.fd > 2)
		close(parse_info.fd);
}
