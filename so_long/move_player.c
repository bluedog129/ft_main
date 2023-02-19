#include "so_long.h"

static int	move_posisible(t_game *map_info, int new_x, int new_y)
{
	char	new_location;

	new_location = map_info->map[new_y][new_x];
	if (new_location == '1')
		return (-1);
	if (new_location == 'C')
		map_info->collect_exit_player[0]--;
	else if (new_location == 'M')
	{
		print_messages("bye bye dino...\n");
		exit(0);
	}
	else if (new_location == 'E')
	{
		if (map_info->collect_exit_player[0] != 0)
			return (-1);
		print_messages("Congratulations! Mission complete :D\n");
		exit(0);
	}
	return (1);
}

static void	move_result(t_game *map_info, int new_x, int new_y)
{
	int	previous_x;
	int	previous_y;

	previous_x = map_info->player_position[1];
	previous_y = map_info->player_position[0];
	new_x += previous_x;
	new_y += previous_y;
	if (move_posisible(map_info, new_x, new_y) == -1)
		return ;
	map_info->map[new_y][new_x] = 'P';
	map_info->map[previous_y][previous_x] = 0;
	map_info->player_position[1] = new_x;
	map_info->player_position[0] = new_y;
}

static void press_keyboard(t_game *map_info, int keycode)
{
    if (keycode == KEY_UP)
        move_result(map_info, 0, -1);
    else if (keycode == KEY_DOWN)
        move_result(map_info, 0, 1);
    else if (keycode == KEY_LEFT)
	{
		map_info->left = 1;
        move_result(map_info, -1, 0);
	}
	else if (keycode == KEY_RIGHT)
	{
		map_info->left = 0;
        move_result(map_info, 1, 0);
	}
	if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		map_info->moving_count++;
		print_messages("\nDino's footprint : ");
		ft_putnbr_fd(map_info->moving_count, 1);
		print_messages("\n");
	}
}

int move_player(int keycode, void *param)
{
    t_game *map_info;

    map_info = (t_game *)param;
    if (keycode == KEY_ESC)
    {
        print_messages("You pressed the exit_button!\n");
        exit(0);
    }
    press_keyboard(map_info, keycode);
    return (0);
}
