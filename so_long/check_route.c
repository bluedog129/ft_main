#include "so_long.h"

static int	dfs(int width, char map[][width], char collect, \
int x, int y)
{
	int count;

	count = 0;
	if (collect == 'C')
		if (map[y][x] == 'E')
			return (0);
	if (map[y][x] == '1' || map[y][x] == 'x')
		return (0);
	if (map[y][x] != 'x')
	{
		if (map[y][x] == collect)
		{
			map[y][x] = 'x';
			count++;
		}
		map[y][x] = 'x';
		count += dfs(width, map, collect, x + 1, y);
		count += dfs(width, map, collect, x, y + 1);
		count += dfs(width, map, collect, x - 1, y);
		count += dfs(width, map, collect, x, y - 1);
	}
	return (count);
}


static void map_duplicate(char **map, int height, \
			int width, char map_dup[height][width])
{
	int	i;
	int	j;

	i = 0;
    while (i < height)
	{
		j = 0;
		while (j < width)
		{
			map_dup[i][j] = map[i][j];
			j++;
		}
		i++;
    }
}

int	check_route(t_game *map_info, int player_pos[2])
{
	int		collect;
	int		exit;
	char	map_dup[map_info->height][map_info->width];

	collect = 0;
	exit = 0;
	ft_memset(map_dup, 0, sizeof(map_dup));
	map_duplicate(map_info->map, map_info->height, map_info->width, map_dup);
	collect += dfs(map_info->width, map_dup, 'C', player_pos[1], player_pos[0]);
	map_duplicate(map_info->map, map_info->height, map_info->width, map_dup);
	exit += dfs(map_info->width, map_dup, 'E', player_pos[1], player_pos[0]);
	if (collect != map_info->collect_exit_player[0] || exit != 1)
		return (ERROR);
	return (0);
}

