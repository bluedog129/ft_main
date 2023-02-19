#include "so_long.h"

static void	put_image(t_game *map_info, int x, int y, void *img)
{
	mlx_put_image_to_window(map_info->mlx, \
		map_info->dino_advanture, img, x * 64, y * 64);
}

static void	display_player(t_game *map_info)
{
	static int	index;

	index = (index + 1) % 15;
	if (map_info->left == 1)
	{
		put_image(map_info, map_info->player_position[1], \
			map_info->player_position[0], map_info->dino_left[index]);
	}
	else
	{
		put_image(map_info, map_info->player_position[1], \
			map_info->player_position[0], map_info->dino_right[index]);
	}
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
	else if (map_info->map[y][x] == 'P')
		display_player(map_info);
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

	if (prev_moving_count == 0 || map_info->moving_count != prev_moving_count)
	{
		moving_count_str = ft_itoa(map_info->moving_count);
		mlx_string_put(map_info->mlx, map_info->dino_advanture, \
						20, 20, 0x0000FF, moving_count_str);
		free(moving_count_str);
		prev_moving_count = map_info->moving_count;
	}
	display_map(map_info);
	return (0);
}
