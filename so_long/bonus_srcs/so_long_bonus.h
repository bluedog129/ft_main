/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:01:27 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/21 18:00:54 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>

# define MOVE_THRESHOLD 10

enum e_definition
{
	ERROR = -1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	KEY_DOWN = 1,
	KEY_UP = 13,
	KEY_ESC = 53,
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
int		handle_close_button(void);
void	free_array(char **array, int size);
void	finish_game(t_game *map_info);
int		validate_arg(int ac, char **av);

#endif