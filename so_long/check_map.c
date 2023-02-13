#include "so_long.h"

static int	dfs(int width, char map[][width], char collect_or_exit, \
int x, int y)
{
	int count;

	count = 0;
	if (map[x][y] == '1' || map[x][y] == 'x')
		return 0;
	if (map[x][y] != 'x')
	{
		if (map[x][y] == collect_or_exit)
		{
			map[x][y] = 'x';
			return 1;
		}
		map[x][y] = 'x';
		count += dfs(width, map, collect_or_exit, x + 1, y);
		count += dfs(width, map, collect_or_exit, x, y + 1);
		count += dfs(width, map, collect_or_exit, x - 1, y);
		count += dfs(width, map, collect_or_exit, x, y - 1);
	}
	return count;
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
			// printf("%c ", map_dup[i][j]);
			map_dup[i][j] = map[i][j];
			// printf("%c ", map_dup[i][j]);
			j++;
		}
		// printf("\n");
		i++;
    }
}

static int	check_route(t_map_info *map_info, int player_pos[2])
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
	printf("collect = %d, exit = %d\n", collect, exit);
	if (collect < 1)
		return (ERROR);
	if (exit != 1)
		return (ERROR);
	return 0;
}


static int get_player_position(t_map_info *map_info, int *player_position)
{
	char **map;
	int y;
	int x;

	map = map_info->map;
	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == 'P')
			{
				player_position[0] = y;
				player_position[1] = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (ERROR);
}

static int	is_surrounded_by_wall(char **map, int height, int width)
{
	int	i;
	
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width -1] != '1')
			return (ERROR);
		i++;
	}
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (ERROR);
		i++;
	}
	return (0);
}

int	check_map(t_map_info *map_info)
{
	int player_position[2];

	ft_memset(player_position, 0, sizeof(player_position));
	if (get_player_position(map_info, player_position) == ERROR)
		return (ERROR);
	if (is_surrounded_by_wall(map_info->map, map_info->height, \
			map_info->width) == ERROR)
		return (ERROR);
	if (check_route(map_info, player_position) == ERROR)
		return (ERROR);
	return 0;
}




// static int check_component(t_map_info *map_info)
// {
// 	int i;
// 	int j;
// 	int collect_exit_player[3];

// 	i = -1;
// 	ft_memset(collect_exit_player, 0, sizeof(collect_exit_player));
// 	while (map_info->map[++i])
// 	{
// 		j = 0;
// 		while (map_info->map[i][j])
// 		{
// 			if (map_info->map[i][j] == 'C')
// 				collect_exit_player[0]++;
// 			else if (map_info->map[i][j] == 'E')
// 				collect_exit_player[1]++;
// 			else if (map_info->map[i][j] == 'P')
// 				collect_exit_player[2]++;
// 			j++;
// 		}
// 	}
// 	if (collect_exit_player[0] < 1 || collect_exit_player[1] != 1 || \
// 		collect_exit_player[2] != 1)
// 		return (ERROR);
// 	return (0);
// }
