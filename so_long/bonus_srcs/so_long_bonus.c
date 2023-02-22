/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:01:32 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/21 22:36:43 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	render_loop(t_game *map_info)
{
	mlx_clear_window(map_info->mlx, map_info->dino_advanture);
	display_image(map_info);
	move_enemy(map_info);
	return (0);
}

static int	game_controller(t_game *map_info)
{
	mlx_hook(map_info->dino_advanture, 17, 0, handle_close_button, NULL);
	mlx_key_hook(map_info->dino_advanture, move_player, map_info);
	mlx_loop_hook(map_info->mlx, render_loop, map_info);
	return (0);
}

void	so_long(char *map_file)
{
	t_game	*map_info;

	map_info = malloc(sizeof(t_game));
	ft_memset(map_info, 0, sizeof(t_game));
	if (map_init(map_info, map_file) == ERROR)
		exit(0);
	if (check_map(map_info) == ERROR)
		finish_game(map_info);
	open_image(map_info);
	game_controller(map_info);
	mlx_loop(map_info->mlx);
	finish_game(map_info);
}