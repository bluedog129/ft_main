#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
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
void	so_long(t_map_info *map_info);
int		check_map(t_map_info *map_info);
int		check_route(t_map_info *map_info, int player_pos[2]);

#endif