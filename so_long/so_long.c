#include "so_long.h"

static int render_loop(t_game *map_info)
{
    static int	img_index;
	
    mlx_clear_window(map_info->mlx, map_info->dino_advanture);
    img_index = (img_index + 1) % 15;
    display_image(map_info, img_index);
	move_enemy(map_info);
    return (0);
}

static int game_controller(t_game *map_info)
{
    mlx_key_hook(map_info->dino_advanture, move_player, map_info);
    mlx_loop_hook(map_info->mlx, render_loop, map_info);
    while (1)
    {
        usleep(FRAME_TIME_US);
		mlx_loop(map_info->mlx);
    }
    return (0);
}

void	so_long(char *map_file)
{
	t_game *map_info;

	map_info = malloc(sizeof(t_game));
	if (map_init(map_info, map_file) == ERROR)
		return ;
	if (check_map(map_info) == ERROR)
		return ;
	print_map(map_info->map, map_info->height, map_info->width);
	open_image(map_info);
	game_controller(map_info);
	free(map_info);
	return ;
}
