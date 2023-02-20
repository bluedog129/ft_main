/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:56:30 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/20 11:56:31 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>

# define SPRITE_SIZE 32
# define MOVEMENT_SPEED 4
# define FRAME_TIME_US 50000
# define MOVE_THRESHOLD 10

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
	int		moving_count;
}	t_game;

void	print_map(char **map, int height, int width); // 지우기
int		map_init(t_game *map_info, char *map_file);
void	so_long(char *map_file);
int		check_map(t_game *map_info);
int		check_route(t_game *map_info, int player_pos[2]);
void	open_image(t_game *image);
int		display_image(t_game *map_info);
void	print_error(char *msg);
void	print_messages(char *msg);
int		move_player(int keycode, void *param);
void	move_enemy(t_game *map_info);
int		handle_close_button(void *param);

#endif