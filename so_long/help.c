#include "so_long.h"

void print_map(char **map, int height, int width)
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