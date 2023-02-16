#include "so_long.h"

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
	display_image(map_info);
	game_controller(map_info);
	mlx_loop(map_info->mlx);
	free(map_info);
	return ;
}
