#include "so_long.h"


static void move_result(t_game *map_info, int x, int y)
{
    char new_location;
    int previous_x;
    int previous_y;

    previous_x = map_info->player_position[1];
    previous_y = map_info->player_position[0];
    x += previous_x;
    y += previous_y;
    new_location = map_info->map[y][x];
    if (new_location == '1')
        return;
    if (new_location == 'C')
        map_info->collect_exit_player[0]--;
	if (new_location == 'M')
	{
		print_messages("bye bye dino...\n");
		exit(0);
	}
    else if (new_location == 'E')
    {
        if (map_info->collect_exit_player[0] != 0)
            return;
        print_messages("Congulatulations! mission complete :D\n");
        map_info->game_finish = 1;
    }
    map_info->map[y][x] = 'P';
    map_info->map[previous_y][previous_x] = 0;
    map_info->player_position[1] = x;
    map_info->player_position[0] = y;
}

static void move_player(t_game *map_info, int keycode)
{
	if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		map_info->moving_count++;
		print_messages("\nDino's foot print : ");
		ft_putnbr_fd(map_info->moving_count, 1);
		
	}
    if (keycode == KEY_UP)
        move_result(map_info, 0, -1);
    else if (keycode == KEY_DOWN)
        move_result(map_info, 0, 1);
    else if (keycode == KEY_LEFT)
        move_result(map_info, -1, 0);
    else if (keycode == KEY_RIGHT)
        move_result(map_info, 1, 0);
}

static int handle_close_button(int keycode, void *param)
{
    t_game *map_info;

    map_info = (t_game *)param;
    if (keycode == KEY_ESC)
    {
        print_messages("You pressed exit_button!\n");
        exit(0);
    }
    move_player(map_info, keycode);
    return (0);
}

static int render_loop(t_game *loop)
{
    static int img_index = 0;

    mlx_clear_window(loop->mlx, loop->dino_advanture);
    display_image(loop, img_index);
    img_index = (img_index + 1) % 15;
    return (0);
}

int game_controller(t_game *map_info)
{
    mlx_key_hook(map_info->dino_advanture, handle_close_button, map_info);
    mlx_loop_hook(map_info->mlx, render_loop, map_info);
    while (1)
    {
        usleep(FRAME_TIME_US);
        mlx_loop(map_info->mlx);
    }
    return (0);
}
