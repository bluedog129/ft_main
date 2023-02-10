#include "so_long.h"



int	check_route(char **map)
{
	//dfs();
	return 0;
}

// int check_wall(char **map)
// {
// 	return 0;
// }

// int check_component(char **map)
// {
// 	int i;
// 	int j;
// 	int collect_exit_player[3];

// 	i = -1;
// 	ft_memset(collect_exit_player, 0, sizeof(collect_exit_player));
// 	while (map[++i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == 'C')
// 				collect_exit_player[0]++;
// 			else if (map[i][j] == 'E')
// 				collect_exit_player[1]++;
// 			else if (map[i][j] == 'P')
// 				collect_exit_player[2]++;	
// 			j++;
// 		}
// 	}
// 	if (collect_exit_player[0] < 1 || collect_exit_player[1] != 1 || \
// 		collect_exit_player[2] != 1)
// 		return (-1);
// 	return (0);
// }

int	check_map(t_map_info *map_info)
{
	check_wall(map_info);
	check_component(map_info);
	check_route(map_info);
	return 0;
}