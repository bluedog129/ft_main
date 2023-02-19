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
			else if (map_info->map[y][x] == 'M' && (rand() % 5 == 0))
				put_image(map_info, x, y, map_info->enemy[(x + y) % 2]);
			else if (map_info->map[y][x] == 'M')
				put_image(map_info, x, y, map_info->enemy[(x + y) % 2]);
			x++;
		}
		y++;
	}
}

static void display_player(t_game *map_info)
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

// static void display_character(t_game *map_info, int x, int y, void *img)
// {
//     static int move_threshold = 0;
//     int move_probability = 10; // Adjust as needed to control enemy movement frequency

//     // Only update character position if move_threshold exceeds move_probability
//     if (move_threshold >= move_probability) {
//         // Generate random movement direction
//         int move_direction = rand() % 4;

//         // Calculate new position based on movement direction
//         int new_x = x;
//         int new_y = y;
//         if (move_direction == 0) new_y--;
//         else if (move_direction == 1) new_x++;
//         else if (move_direction == 2) new_y++;
//         else new_x--;

//         // Only update position if new location is a valid move
//         if (map_info->map[new_y][new_x] == '0' || map_info->map[new_y][new_x] == 'P') {
//             map_info->map[new_y][new_x] = 'M';
//             map_info->map[y][x] = '0';
//             x = new_x;
//             y = new_y;
//         }
//         move_threshold = 0;
//     }
//     else {
//         move_threshold++;
//     }

//     mlx_put_image_to_window(map_info->mlx, map_info->dino_advanture, img, x * 64, y * 64);
// }

int	display_image(t_game *map_info)
{
	char	*moving_count_str;

	moving_count_str = ft_itoa(map_info->moving_count);
	display_map(map_info);
	display_player(map_info);
    mlx_string_put(map_info->mlx, map_info->dino_advanture, 20, 20, 0x0000FF, moving_count_str);
    free(moving_count_str);
	return (0);
}
