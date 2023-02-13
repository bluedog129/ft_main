#include "so_long.h"

void	so_long(void)
{
	t_map_info *map_info;
	map_info = malloc(sizeof(t_map_info));

	map_init(map_info);
	if (check_map(map_info) == ERROR)
	{
		write(1, "map error\n", 11);
		return ;
	}
	print_map(map_info->map, map_info->height, map_info->width);


	free(map_info);
	return ;
}