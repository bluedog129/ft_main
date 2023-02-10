
#include "so_long.h"

static void print_map(char **map, int height, int width)
{
	int i;
	int	j;

	i = 0;
	printf("\n============== print map ==============\n\n");
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			printf("%c ", map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n=======================================\n");
}

int main(void)
{
	t_map_info *map_info;
	map_info = malloc(sizeof(t_map_info));
	map_init(map_info);
	print_map(map_info->map, map_info->heigth, map_info->width);
	return 0;
}