/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:53:46 by hyojocho          #+#    #+#             */
/*   Updated: 2023/07/06 20:05:26 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	get_texture_path(char **texture_info, t_map *map_info, \
						t_parse_info *parse_info)
{
	if (ft_strncmp(texture_info[0], "NO", 2) == 0)
	{
		map_info->side_info->north_tex = ft_strdup(texture_info[1]);
		parse_info->north_tex_count++;
	}
	else if (ft_strncmp(texture_info[0], "SO", 2) == 0)
	{
		map_info->side_info->south_tex = ft_strdup(texture_info[1]);
		parse_info->south_tex_count++;
	}
	else if (ft_strncmp(texture_info[0], "WE", 2) == 0)
	{
		map_info->side_info->west_tex = ft_strdup(texture_info[1]);
		parse_info->west_tex_count++;
	}
	else if (ft_strncmp(texture_info[0], "EA", 2) == 0)
	{
		map_info->side_info->east_tex = ft_strdup(texture_info[1]);
		parse_info->east_tex_count++;
	}
	else
		return (ERROR);
	return (TRUE);
}
