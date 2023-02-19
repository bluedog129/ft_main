#include "so_long.h"

static int	move_possible_than_move(t_game *map_info, int new_x, int new_y, int enemy_position[2])
{
	char	new_location;

	new_location = map_info->map[new_y][new_x];
	if (new_location == '1' || new_location == 'M' \
		|| new_location == 'E' || new_location == 'C')
		return (-1);
	map_info->map[new_y][new_x] = 'M';
	map_info->map[enemy_position[0]][enemy_position[1]] = '0';
	if (new_location == 'P')
	{
		print_messages("bye bye dino...\n");
		exit(0);
	}
	return (1);
}

static int find_enemy(t_game *map_info, int start_x, int start_y, int enemy_position[2])
{
	int	y;
	int	x;

	y = start_y;
	x = start_x;
	while (y < map_info->height)
	{
		if (y != start_y)
			x = 0;
		while (x < map_info->width)
		{
			if (map_info->map[y][x] == 'M')
			{
				enemy_position[0] = y;
				enemy_position[1] = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

void move_enemy(t_game *map_info)
{
    int enemy_position[2];
    double random;
	double direction;

	ft_memset(enemy_position, 0, sizeof(enemy_position));
    if (find_enemy(map_info, enemy_position[1], enemy_position[0], enemy_position) == -1)
        return;
    srand(time(NULL));
    random = (double)(rand() % 3) - 1;
	direction = (double)(rand() % 2) - 1;
	
	if (direction == 1)
	{
    	if (move_possible_than_move(map_info, (int)(enemy_position[1] + random),\
		enemy_position[0], enemy_position) == -1)
			return ;
	}
	else
	{
		if (move_possible_than_move(map_info, enemy_position[1], \
			(int)(enemy_position[0] + random), enemy_position) == -1)
			return ;
	}
}
