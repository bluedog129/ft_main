#include "so_long.h"


int open_image()
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	void *img6;
	void *img7;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./images/character.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./images/enemy1.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./images/enemy2.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./images/Item.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./images/road.xpm", &img_width, &img_height);
	img6 = mlx_xpm_file_to_image(mlx, "./images/spellbook.xpm", &img_width, &img_height);
	img7 = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 192, 64);
	mlx_put_image_to_window(mlx, win, img5, 0, 64);
	mlx_put_image_to_window(mlx, win, img6, 64, 64);
	mlx_put_image_to_window(mlx, win, img7, 128, 64);
	mlx_loop(mlx);
	return (0);
}


void	setting_img(t_game game)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < game.height)
	{
		wid = 0;
		while (wid < game.width)
		{
			if (game.str_line[hei * game.width + wid] == '1')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.wall, wid * 64, hei * 64);
			}
			else if (game.str_line[hei * game.width + wid] == 'C')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.chest, wid * 64, hei * 64);
			}
			else if (game.str_line[hei * game.width + wid] == 'P')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.chara, wid * 64, hei * 64);
			}
			else if (game.str_line[hei * game.width + wid] == 'E')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.rune, wid * 64, hei * 64);
			}
			else
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.land, wid * 64, hei * 64);
			}
			wid++;
		}
		hei++;
	}
}