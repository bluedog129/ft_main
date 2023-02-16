#include "so_long.h"

void	so_long(char *map_file)
{
	t_game *map_info;

	map_info = malloc(sizeof(t_game));
	map_info->init_check = map_init(map_info, map_file);
	if (map_info->init_check == ERROR || check_map(map_info) == ERROR)
	{
		write(1, "map error\n", 11);
		return ;
	}
	print_map(map_info->map, map_info->height, map_info->width);
	open_image(map_info);
	display_image(map_info);
	// control_player();
	// mlx_hook(map_info->dino_advanture, KEY_PRESS, );
	mlx_loop(map_info->mlx);
	free(map_info);
	return ;
}
