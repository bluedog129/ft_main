#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>   ///// 무조권 지워야 함

enum definition
{
	ERROR = -1,
	KEY_LEFT = 0,
	KEY_RIGHT = 1,
	KEY_DOWN = 2,
	KEY_UP = 13,
	KEY_ESC = 53,
	KEY_RELEASE = 3,
	KEY_PRESS = 2
};

typedef struct map_type
{
	char **map;
	int width;
	int height;
	int x;
	int y;
	int collect_exit_player[3];
	int player_position[2];
}	t_map_info;

void	print_map(char **map, int height, int width); // 지우기
int 	map_init(t_map_info *map_info);
void	so_long(void);
int		check_map(t_map_info *map_info);
int		check_route(t_map_info *map_info, int player_pos[2]);

#endif