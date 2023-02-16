#include "so_long.h"

static void move_result(t_game *map_info, int x, int y)
{
	char	new_location;
	int		previous_x;
	int		previous_y;

	previous_x = map_info->player_position[1];
	previous_y = map_info->player_position[0];
	x += previous_x;
	y += previous_y;
	new_location = map_info->map[y][x];
	if (new_location == '1')
		return ;
	if (new_location == 'C')
		map_info->collect_exit_player[0]--;
	else if (new_location == 'E')
	{
		if (map_info->collect_exit_player[0] != 0)
			return;
		write(1, "congulatulation! mission complete :D\n", 37);
		map_info->game_finish = 1;
	}
	map_info->map[y][x] = 'P';
	map_info->map[previous_y][previous_x] = 0;
	map_info->player_position[1] = x;
	map_info->player_position[0] = y;
}

static void move_player(t_game *map_info, int keycode)
{
	if (keycode == KEY_UP)
		move_result(map_info, 0, -1);
	else if (keycode == KEY_DOWN)
		move_result(map_info, 0, 1);
	else if (keycode == KEY_LEFT)
		move_result(map_info, -1, 0);
	else if (keycode == KEY_RIGHT)
		move_result(map_info, 1, 0);
}

static int key_handler(int keycode, void *param)
{
	t_game	*map_info;
	
	map_info = (t_game *)param;
	if (keycode == KEY_ESC)
	{
		write(1, "you pressed exit_button!\n", 25);
		exit(0);
	}
	move_player(map_info, keycode);
	return (0);
}

static int render_loop(t_game *loop)
{
	mlx_clear_window(loop->mlx, loop->dino_advanture);
	display_image(loop);
	return (0);
}

int game_controller(t_game *map_info)
{
    mlx_key_hook(map_info->dino_advanture, key_handler, map_info);
    mlx_loop_hook(map_info->mlx, render_loop, map_info);
    return (0);
}
