#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>   ///// 무조권 지워라

typedef struct map_type
{
	char **map;
	int width;
	int heigth;

}	t_map_info;

int 	map_init(t_map_info *map_info);
void	so_long(t_map_info *map_info);
int		check_map(t_map_info *map_info);

#endif