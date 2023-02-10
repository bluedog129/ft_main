#include "so_long.h"

static void	copy_map(char (*tmp)[1000], t_map_info *map)
{
	int	i;

	map->map = malloc(sizeof(char *) * map->heigth);
	i = 0;
	while (i < map->heigth)
	{
		map->map[i] = malloc(sizeof(char) * map->width);
		ft_memcpy(map->map[i], tmp[i], map->width);
		i++;
	}
}

t_map_info *open_map(t_map_info *map)
{
	char	tmp[1000][1000];
	char	*line;
	int		fd;
	int		i;
	int		j;

	fd = open("./map.txt", O_RDONLY);
	i = 0;
	while(1)
	{
		j = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break;
		while(*(line + j))
		{
			tmp[i][j] = (char)*(line + j);
			j++;
		}
		if (i == 0)
			map->width = j;
		if (map->width != j)
			break;
		i++;
		free(line);
	}
	map->heigth = i;
	copy_map(tmp, map);
	return (map);
}
