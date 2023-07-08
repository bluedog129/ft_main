/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:42:18 by hyojocho          #+#    #+#             */
/*   Updated: 2023/07/03 17:44:51 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	validate_cube_file(char *cub_file)
{
	int		index;
	char	*start;
	char	*slash;
	char	*str;

	index = 0;
	start = NULL;
	str = ".cub";
	start = ft_strnstr(cub_file, str, ft_strlen(cub_file));
	if (start == NULL)
		return (ERROR);
	if (start[4] != '\0')
		return (ERROR);
	slash = ft_strrchr(cub_file, '/');
	if (slash == NULL)
		return (1);
	while (++slash != start)
	{
		if (*slash == '.')
			return (ERROR);
	}
	return (SUCCESS);
}

void	validate_args(int argc)
{
	if (argc != 2)
		print_error("Error: Invalid number of arguments\n");
}
