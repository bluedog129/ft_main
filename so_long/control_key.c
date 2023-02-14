# include "so_long.h"

static int	move_player(int keycode, t_map_info *map_info)
{
	int	x;
	int y;

	x = map_info->player_position[0];
	y = map_info->player_position[1];
	if (keycode == KEY_UP && map_info->map[y + 1][x] != 1)
		y++;
	else if (keycode == KEY_DOWN && map_info->map[y - 1][x] != 1)
		y--;
	else if (keycode == KEY_LEFT && map_info->map[y][x - 1] != 1)
		x--;
	else if (keycode == KEY_RIGHT && map_info->map[y][x + 1] != 1)
		x++;
	else if (keycode == KEY_ESC)
		exit(0);
	map_info->player_position[0] = x;
	map_info->player_position[1] = y;
	return (0);
}

int	control_key(t_map_info *map_info)
{
	void		*mlx;
	void		*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "so_long");
	mlx_hook(win, KEY_RELEASE, 0, &move_player, map_info);
	mlx_loop(mlx);
}

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}

void	move_w(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i - g->wid] == 'C')
		g->col_cnt++;
	if (g->str_line[i - g->wid] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if (g->str_line[i - g->wid] != '1' && g->str_line[i - g->wid] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - g->wid] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}