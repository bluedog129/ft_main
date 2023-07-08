/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:24:34 by hyojocho          #+#    #+#             */
/*   Updated: 2023/07/08 16:49:41 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	initialize(t_map *map_info, t_parse_info *parse_info)
{
	ft_memset((void *)map_info, 0, sizeof(t_map));
	ft_memset((void *)parse_info, 0, sizeof(t_parse_info));
	map_info->head_node = (t_map_node *)malloc(sizeof(t_map_node));
	if (map_info->head_node == NULL)
		exit_error("Error: map allocate fail", map_info, parse_info);
	map_info->head_node->line = NULL;
	map_info->head_node->next = NULL;
}
