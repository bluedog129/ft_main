/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:02:03 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/21 16:02:05 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_image(t_game *map_info, int x, int y, void *img)
{
	mlx_put_image_to_window(map_info->mlx, \
		map_info->dino_advanture, img, x * 64, y * 64);
}

static void	load_dino_sprites(t_game *map_info, int x, int y)
{
	static int	frame = 0;
	static int	delay = 3;

	if (map_info->left == 1)
		put_image(map_info, x, y, \
			map_info->dino_left[frame / delay % 15]);
	else
		put_image(map_info, x, y, \
			map_info->dino_right[frame / delay % 15]);
	frame++;
}

static void	display_map_tiles(t_game *map_info, int x, int y)
{
	if (map_info->map[y][x] == '1')
		put_image(map_info, x, y, map_info->wall);
	else
		put_image(map_info, x, y, map_info->road);
	if (map_info->map[y][x] == 'C')
		put_image(map_info, x, y, map_info->item);
	else if (map_info->map[y][x] == 'E')
		put_image(map_info, x, y, map_info->spellbook);
	else if (map_info->map[y][x] == 'M' && (rand() % 5 == 0))
		put_image(map_info, x, y, map_info->enemy[(x + y) % 2]);
	else if (map_info->map[y][x] == 'M')
		put_image(map_info, x, y, map_info->enemy[(x + y) % 2]);
}

static void	display_map(t_game *map_info)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			display_map_tiles(map_info, x, y);
			x++;
		}
		y++;
	}
}

int	display_image(t_game *map_info)
{
	static int	prev_moving_count;
	char		*moving_count_str;

	display_map(map_info);
	load_dino_sprites(map_info, \
	map_info->player_position[1], map_info->player_position[0]);
	moving_count_str = ft_itoa(map_info->moving_count);
	mlx_string_put(map_info->mlx, map_info->dino_advanture, \
					20, 20, 0x0000FF, moving_count_str);
	free(moving_count_str);
	prev_moving_count = map_info->moving_count;
	return (0);
}