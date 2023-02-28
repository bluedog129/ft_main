/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:54:19 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/28 18:51:06 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_not_digit(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if(av[i][j] == '-')
				j++;
			if(ft_isdigit(av[i][j]) == 0)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (VALIDATE_PASS);
}

static int	validate_not_duplicate(char **av)
{
	int i;
	int j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (VALIDATE_PASS);
}

static int	validate_range(char **av)
{
	int	i;

	while (av[i])
	{
		if (INT_MIN > ft_atoi(av[i]) || ft_atoi(av[i]) > INT_MAX)
			return (ERROR);
	}
	return (VALIDATE_PASS);
}

int	validate_args(int ac, char **av)
{
	if (ac < 2)
		print_error("ERROR : args_not_digit_error");
	if (validate_not_digit(av) == ERROR)
		print_error("ERROR : args_type_error");
	if (validate_not_duplicate(av) == ERROR)
		print_error("ERROR : args_duplicate_error");
	if (validate_range(av) == ERROR)
		print_error("ERROR : args_range_error");
	return (VALIDATE_PASS);
}
