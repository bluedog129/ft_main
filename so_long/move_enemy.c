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
    int new_x;
    int new_y;
    int move_direction;
    int can_move;
    int enemy_position[2];
    static int enemy_move_counter = 0;

    srand(time(NULL));
    ft_memset(enemy_position, 0, sizeof(enemy_position));
    if (find_enemy(map_info, enemy_position[1], enemy_position[0], enemy_position) == -1)
        return;

    enemy_move_counter++;
    if (enemy_move_counter >= MOVE_THRESHOLD)
        enemy_move_counter = 0;
    else
        return;

    move_direction = rand() % 4;
    new_x = enemy_position[1];
    new_y = enemy_position[0];
    if (move_direction == 0)
        new_y--;
    else if (move_direction == 1)
        new_x++;
    else if (move_direction == 2)
        new_y++;
    else
        new_x--;
    can_move = move_possible_than_move(map_info, new_x, new_y, enemy_position);
    if (can_move == -1)
        return;
    enemy_position[1] = new_x;
    enemy_position[0] = new_y;
	usleep(500000);
}