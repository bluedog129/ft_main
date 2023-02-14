#ifndef SO_LONG_H
# define SO_LONG_H
# define KEW_RELEASE	0
# define KEY_PRESS		1
# define KEY_ESC		53
# define KEY_LEFT		0
# define KEY_RIGHT		1
# define KEY_DOWN		2
# define KEY_UP			3

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>   ///// 무조권 지워야 함

typedef struct map_type
{
	char **map;
	int width;
	int height;
	int x;
	int y;
	int collect_exit_player[3];
}	t_map_info;

enum e_return_value
{
	ERROR = -1
};

void	print_map(char **map, int height, int width); // 지우기
int 	map_init(t_map_info *map_info);
void	so_long(void);
int		check_map(t_map_info *map_info);
int		check_route(t_map_info *map_info, int player_pos[2]);

#endif