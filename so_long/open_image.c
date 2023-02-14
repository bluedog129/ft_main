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
	img = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./images/chara.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./images/chest.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./images/chest_open.xpm", &img_width, &img_height);
	img6 = mlx_xpm_file_to_image(mlx, "./images/rune.xpm", &img_width, &img_height);
	img7 = mlx_xpm_file_to_image(mlx, "./images/rune_light.xpm", &img_width, &img_height);
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

void	map_read(char *filename, t_game *game)
{
	int  fd;
	char *line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game->hei = 0;
	game->wid = ft_strlen(line) - 1;
	game->str_line = ft_strdup_without_newline(line);
	free(line);
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		if (line)
		{
			game->str_line = ft_strjoin_without_newline(game->str_line, line);
		}
	}
	close(fd);
	printf("%s\n", game->str_line);
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