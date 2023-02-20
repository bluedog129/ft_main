/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:56:38 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/20 11:56:39 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*xpm_to_image(t_game *image, char *address)
{
	int	width;
	int	height;

	return (mlx_xpm_file_to_image(image->mlx, address, &width, &height));
}

static void	open_dino_right(t_game *image)
{
	image->dino_right[0] = xpm_to_image(image, "./images/dino/right/10.xpm");
	image->dino_right[1] = xpm_to_image(image, "./images/dino/right/11.xpm");
}

static void	open_dino_left(t_game *image)
{
	image->dino_left[0] = xpm_to_image(image, "./images/dino/left/10.xpm");
	image->dino_left[1] = xpm_to_image(image, "./images/dino/left/11.xpm");
}

static void	open_components(t_game *image)
{
	image->enemy[0] = xpm_to_image(image, "./images/enemy/1.xpm");
	image->enemy[1] = xpm_to_image(image, "./images/enemy/2.xpm");
	image->item = xpm_to_image(image, "./images/item.xpm");
	image->road = xpm_to_image(image, "./images/road.xpm");
	image->spellbook = xpm_to_image(image, "./images/spellbook.xpm");
	image->wall = xpm_to_image(image, "./images/wall.xpm");
}

void	open_image(t_game *image)
{
	image->mlx = mlx_init();
	image->dino_advanture = mlx_new_window(image->mlx, \
		image->width * 64, image->height * 64, "dino_advanture");
	open_dino_right(image);
	open_dino_left(image);
	open_components(image);
}
