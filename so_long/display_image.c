# include "so_long.h"

static void	put_image(t_game *map_info, int x, int y, void *img)
{
	mlx_put_image_to_window(map_info->mlx, \
		map_info->dino_advanture, img, x * 64, y * 64);
}

static void display_map(t_game *map_info)
{
	int		y;
	int		x;

	y = 0;
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			put_image(map_info, x, y, map_info->road);
			if (map_info->map[y][x] == '1')
				put_image(map_info, x, y, map_info->wall);
			else if (map_info->map[y][x] == 'C')
				put_image(map_info, x, y, map_info->item);
			else if (map_info->map[y][x] == 'E')
				put_image(map_info, x, y, map_info->spellbook);
			else if (map_info->map[y][x] == 'M')
				put_image(map_info, x, y, map_info->enemy[0]);
			x++;
		}
		y++;
	}
}

static void display_player(t_game *map_info, int index)
{
	put_image(map_info, map_info->player_position[1], \
		map_info->player_position[0], map_info->dino_right[index]);
}

int	display_image(t_game *map_info, int index)
{
	display_map(map_info);
	display_player(map_info, index);
	// move_enemy(map_info);
	char *moving_count_str = ft_itoa(map_info->moving_count);
    mlx_string_put(map_info->mlx, map_info->dino_advanture, 30, 30, 0x0000FF, moving_count_str);
    free(moving_count_str);
	return (0);
}
