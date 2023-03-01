/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:54:19 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/01 18:51:44 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_not_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-')
		{
			if (av[i][j + 1] == '0')
				return (ERROR);
			j++;
		}
		while (av[i][j])
		{
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

	i = 1;
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
	int			i;
	long long	arg_num;

	i = 1;
	while (av[i])
	{
		arg_num = ft_atol(av[i]);
		if (INT_MIN > arg_num || arg_num > INT_MAX)
			return (ERROR);
		i++;
	}
	return (VALIDATE_PASS);
}

int	validate_args(int ac, char **av)
{
	if (ac < 2)
	{
		print_error("ERROR : digit_args_not_inputed_error\n");
		return (ERROR);
	}
	if (validate_not_digit(av) == ERROR)
	{
		print_error("ERROR : args_type_error\n");
		return (ERROR);
	}
	if (validate_not_duplicate(av) == ERROR)
	{
		print_error("ERROR : args_duplicate_error\n");
		return (ERROR);
	}
	if (validate_range(av) == ERROR)
	{
		print_error("ERROR : args_range_error\n");
		return (ERROR);
	}
	return (VALIDATE_PASS);
}
