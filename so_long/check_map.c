#include "so_long.h"

static int	dfs(char **map, char component, int x, int y)
{
	int count;

	if (map[x][y] == '1')
		return (0);
	if (map[x][y] != 'x')
	{
		if (map[x][y] == component)
		{
			map[x][y] = 'x';
			return (1);
		}
		map[x][y] = 'x';
		count = 0;
		count += dfs(map, component, x + 1, y);
		count += dfs(map, component, x, y + 1);
		count += dfs(map, component, x - 1, y);
		count += dfs(map, component, x, y - 1);
		return (count);
	}
	return (0);
}

static void map_duplicate(char **map, int height, \
			int width, char map_dup[height][width])
{
	int	i;

	i = 0;
    while (i < height) 
	{
		ft_memcpy(map_dup[i], map[i], width * sizeof(char));
		i++;
    }
}

static int	check_route(t_map_info *map_info, int player_pos[2])
{
	int		collect_count;
	int		exit_count;
	char	map_dup[map_info->height][map_info->width];

	ft_memset(map_dup, 0, sizeof(map_dup));
	map_duplicate(map_info->map, map_info->height, map_info->width, map_dup);
	collect_count = dfs((char **)map_dup, 'c', player_pos[1], player_pos[0]);
	exit_count = dfs((char **)map_dup, 'e', player_pos[1], player_pos[0]);
	if (collect_count < 1)
		return (ERROR);
	if (exit_count != 1)
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
	
}

int	check_map(t_map_info *map_info)
{
	int player_position[2];

	ft_memset(player_position, 0, sizeof(player_position));
	if (get_player_position(map_info, player_position) == ERROR)
		return (ERROR);
	if (surround_wall)
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
