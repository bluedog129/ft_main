/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choihyojong <choihyojong@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:57:09 by hyojocho          #+#    #+#             */
/*   Updated: 2023/07/09 16:14:53 by choihyojong      ###   ########.fr       */
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
			parse_info->start_position_count++;
		else if (line[i] == 'S')
			parse_info->start_position_count++;
		else if (line[i] == 'W')
			parse_info->start_position_count++;
		else if (line[i] == 'E')
			parse_info->start_position_count++;
		i++;
	}
}