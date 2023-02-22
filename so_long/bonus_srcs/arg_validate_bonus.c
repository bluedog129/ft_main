/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:57:30 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/22 20:10:10 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	find_end_ber(char *str, char *ber)
{
	int	start_ber;

	start_ber = ft_strlen(str) - 4;
	while (str[start_ber])
	{
		if (str[start_ber] != *ber)
			return (ERROR);
		ber++;
		start_ber++;
	}
	return (1);
}

static int	validate_form(char *str, char c)
{
	int	count;

	count = 0;
	if (*str == '.')
		str++;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count == 1);
}

int	validate_arg(int ac, char **av)
{
	if (ac != 2)
	{
		print_error("arg error\n");
		return (ERROR);
	}
	if (validate_form(av[1], '.') == 0)
	{
		print_error("arg error\n");
		return (ERROR);
	}
	if (find_end_ber(av[1], ".ber") == ERROR)
	{
		print_error("arg error\n");
		return (ERROR);
	}
	return (1);
}
