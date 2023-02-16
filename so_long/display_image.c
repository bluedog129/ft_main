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
			x++;
		}
		y++;
	}
}

static void display_player(t_game *map_info)
{
	put_image(map_info, map_info->player_position[1], \
		map_info->player_position[0], map_info->dino_right[0]);
}

// static void display_enemy(t_game *map_info);

int	display_image(t_game *map_info)
{
	display_map(map_info);
	display_player(map_info);
	// display_enemy(map_info);
	return (0);
}
