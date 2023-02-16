#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>   ///// 무조권 지워야 함

enum e_definition
{
	ERROR = -1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	KEY_DOWN = 1,
	KEY_UP = 13,
	KEY_ESC = 53,
	KEY_RELEASE = 3,
	KEY_PRESS = 2
};

typedef struct game_type
{
	char	**map;
	int		width;
	int		height;
	int		collect_exit_player[3];
	int		player_position[2];
	void	*mlx;
	void	*dino_advanture;
	void	*dino_left[15];
	void	*dino_right[15];
	void	*enemy[2];
	void	*wall;
	void	*road;
	void	*item;
	void	*spellbook;
	int		left;
	int		game_finish;
}	t_game;

void	print_map(char **map, int height, int width); // 지우기
int 	map_init(t_game *map_info, char *map_file);
void	so_long(char *map_file);
int		check_map(t_game *map_info);
int		check_route(t_game *map_info, int player_pos[2]);
void	open_image(t_game *image);
int		display_image(t_game *map_info);
int		game_controller(t_game *map_info);


#endif