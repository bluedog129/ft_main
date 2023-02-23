/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:38:42 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/23 19:49:53 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	char	new_location;

	new_location = game->map[new_y][new_x];
	if (new_location == '1' || new_location == 'M' || \
		new_location == 'E' || new_location == 'C')
		return (0);
	if (new_location == 'P')
	{
		print_messages("bye bye dino...\n");
		finish_game(game);
	}
	return (1);
}

static int	get_random_direction(void)
{
	return (rand() % 4);
}

static int	move_enemy_in_direction(t_game *game, \
	int direction, int *enemy_position)
{
	int	new_x;
	int	new_y;

	new_x = enemy_position[1];
	new_y = enemy_position[0];
	if (direction == 0)
		new_y--;
	else if (direction == 1)
		new_x++;
	else if (direction == 2)
		new_y++;
	else if (direction == 3)
		new_x--;
	else
		return (0);
	if (!is_valid_move(game, new_x, new_y))
		return (0);
	game->map[new_y][new_x] = 'M';
	game->map[enemy_position[0]][enemy_position[1]] = '0';
	put_image(game, enemy_position[1], enemy_position[0], game->road);
	put_image(game, new_x, new_y, game->enemy[(new_x + new_y) % 2]);
	enemy_position[1] = new_x;
	enemy_position[0] = new_y;
	return (1);
}

static int	move_randomely(t_game *game, int *enemy_position)
{
	int			direction;

	if (find_enemy(game, enemy_position[1], \
		enemy_position[0], enemy_position) == -1)
		return (-1);
	direction = get_random_direction();
	move_enemy_in_direction(game, direction, &enemy_position[0]);
	return (1);
}

void	move_enemy(t_game *game)
{
	static int	enemy_move_counter;
	static int	enemy_position[2];
	static int	count;
	int			move_num;

	enemy_move_counter++;
	if (count == 0)
	{
		count = game->num_cepm[3];
		ft_memset(enemy_position, 0, sizeof(enemy_position));
	}
	if (enemy_move_counter < MOVE_THRESHOLD)
		return ;
	enemy_move_counter = 0;
	move_num = 3;
	while (move_num)
	{
		move_randomely(game, enemy_position);
		enemy_position[1]++;
		move_num--;
	}
	count--;
	return ;
}
