/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:38:11 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/01 17:46:30 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_percent_f_minus(t_arrayList *arraylist)
{
	int	width_count;

	width_count = 0;
	while (al_get(arraylist, 0) == ' ')
	{
		al_remove_front(arraylist);
		width_count++;
	}
	while (width_count-- > 0)
		al_insert_back(arraylist, ' ');
}

void	apply_percent_f_zero(t_options *options_check, t_arrayList *arraylist)
{
	int	width_count;

	width_count = 0;
	while (al_get(arraylist, 0) == ' ')
	{
		al_remove_front(arraylist);
		width_count++;
	}
	while (width_count-- > 0)
		al_insert_front(arraylist, '0');
	if (options_check->flag_minus == SWITCH_ON)
	{
		width_count = 0;
		while (al_get(arraylist, arraylist->size) == ' ')
		{
			al_remove_back(arraylist);
			width_count++;
		}
		while (width_count-- > 0)
			al_insert_back(arraylist, '0');
	}
}

void	apply_str_f_minus(t_options *options_check, t_arrayList *arraylist)
{
	int		width_len;
	int		str_len;

	str_len = options_check->str_len;
	width_len = options_check->width - str_len;
	while (width_len > 0)
	{
		al_remove_front(arraylist);
		width_len--;
	}
	width_len = options_check->width - str_len;
	while (width_len > 0)
	{
		al_insert_back(arraylist, ' ');
		width_len--;
	}
}

void	apply_dp_f_minus(t_arrayList *arraylist)
{
	int	width_count;

	width_count = 0;
	while (al_get(arraylist, 0) == ' ')
	{
		al_remove_front(arraylist);
		width_count++;
	}
	while (width_count > 0)
	{
		al_insert_back(arraylist, ' ');
		width_count--;
	}
}

void	apply_d_f_zero(t_options *options_check, t_arrayList *arraylist)
{
	int	minus_flag;
	int	width_count;

	minus_flag = 0;
	width_count = 0;
	while (al_get(arraylist, 0) == ' ' || al_get(arraylist, 0) == '-')
	{
		if (al_get(arraylist, 0) == '-')
			minus_flag = 1;
		else if (al_get(arraylist, 0) == ' ')
			width_count++;
		al_remove_front(arraylist);
	}
	if (options_check->flag_space == SWITCH_ON && minus_flag == 0)
		width_count--;
	while (width_count-- > 0)
		al_insert_front(arraylist, '0');
	if (minus_flag == 1)
		al_insert_front(arraylist, '-');
}
