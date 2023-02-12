#include "so_long.h"

void	so_long(t_map_info *map_info)
{
	map_init(map_info);
	check_map(map_info);
	print_map(map_info->map, map_info->height, map_info->width);
}