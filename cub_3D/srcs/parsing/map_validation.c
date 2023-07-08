/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:57:09 by hyojocho          #+#    #+#             */
/*   Updated: 2023/07/08 16:16:00 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	valid_map_characters(char *line, t_map *map_info, \
								t_parse_info *parse_info)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'E' && \
			line[i] != 'W' && line[i] != 'S' && line[i] != 'N' && \
			line[i] != ' ')
			exit_error("Error: invalid map characters", map_info, parse_info);
		else if (line[i] == 'N')
			parse_info->north_tex_count++;
		else if (line[i] == 'S')
			parse_info->south_tex_count++;
		else if (line[i] == 'W')
			parse_info->west_tex_count++;
		else if (line[i] == 'E')
			parse_info->east_tex_count++;
		i++;
	}
}