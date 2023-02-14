# include "so_long.h"

typedef struct s_param{
	int		x;
	int		y;
}				t_param;

void			param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int				key_press(int keycode, t_param *param)
{
	static int a = 0;

	if (keycode == KEY_UP)
		param->y++;
	else if (keycode == KEY_DOWN)
		param->y--;
	else if (keycode == KEY_LEFT)
		param->x--;
	else if (keycode == KEY_RIGHT)
		param->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", param->x, param->y);
	return (0);
}

int			main(void)
{
	void		*mlx;
	void		*win;
	t_param		param;

	param_init(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_loop(mlx);
}