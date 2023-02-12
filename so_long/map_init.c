#include "so_long.h"

static int check_rectangular(char (*tmp)[1000], t_map_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (tmp[i][j])
			j++;
		if (map_info->height == i + 1)
			j++;
		if (map_info->width + 1 != j)
			return (ERROR);
		i++;
	}
	return (1);
}

static void	copy_map(char (*tmp)[1000], t_map_info *map_info)
{
	int	i;

	map_info->map = malloc(sizeof(char *) * map_info->height);
	i = 0;
	while (i < map_info->height)
	{
		map_info->map[i] = malloc(sizeof(char) * map_info->width);
		ft_memcpy(map_info->map[i], tmp[i], map_info->width);
		i++;
	}
}

static int open_map(char (*tmp)[1000], t_map_info *map_info)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	fd = open("./docs/map.txt", O_RDONLY);
	if (fd < 0)
		return (ERROR);
	i = 0;
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		j = -1;
		while(line[++j])
			tmp[i][j] = line[j];
		tmp[i][j] = '\0';
		i++;
		free(line);
	}
	map_info->width = j;
	map_info->height = i;
	return (0);
}

int map_init(t_map_info *map_info)
{
	char	tmp[1000][1000];

	if (open_map(tmp, map_info) == ERROR)
		return (ERROR);
	if (check_rectangular(tmp, map_info) == ERROR)
	{
		write(1, "wall_validate_error", 19);
		return (ERROR);
	}
	copy_map(tmp, map_info);
	return (1);
}
