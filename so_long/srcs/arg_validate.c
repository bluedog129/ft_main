/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:57:30 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/24 13:22:09 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	print_arg_error(void)
{
	error_exit("arg error\n");
	return (ERROR);
}

int	validate_arg(int ac, char **av)
{
	int		index;
	char	*start;
	char	*slash;
	char	*str;

	index = 0;
	start = NULL;
	str = ".ber";
	if (ac != 2)
		return (print_arg_error());
	start = ft_strnstr(av[1], str, ft_strlen(av[1]));
	if (start == NULL)
		return (print_arg_error());
	if (start[4] != '\0')
		return (print_arg_error());
	slash = ft_strrchr(av[1], '/');
	if (slash == NULL)
		return (1);
	while (++slash != start)
	{
		if (*slash == '.')
			return (print_arg_error());
	}
	return (1);
}
