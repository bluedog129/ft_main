
#include "so_long.h"

int main(void)
{
	t_map_info *map_info;
	map_info = malloc(sizeof(t_map_info));
	so_long(map_info);
	print_map(map_info->map, map_info->height, map_info->width);
	free(map_info);
	return 0;
}