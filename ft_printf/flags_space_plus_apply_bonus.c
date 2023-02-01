/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_space_plus_apply_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:12:56 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/30 19:43:58 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	apply_d_f_space(t_options *options_check, t_arrayList *arraylist)
{
	if (al_get(arraylist, 0) == ' ' || al_get(arraylist, 0) == '-')
		return ;
	if (options_check->flag_minus == SWITCH_ON)
	{
		if (al_get(arraylist, arraylist->size - 1) == ' ')
			al_remove_back(arraylist);
		al_insert_front(arraylist, ' ');
		return ;
	}
	al_insert_front(arraylist, ' ');
}

static void	apply_d_f_switch(t_options *options_check, t_arrayList *arraylist)
{
	if (options_check->precision_switch == SWITCH_OFF && \
		options_check->width_switch == SWITCH_ON && \
		options_check->flag_zero == SWITCH_ON && \
		al_get(arraylist, 0) == '0')
	{
		al_remove_front(arraylist);
		al_insert_front(arraylist, '+');
		return ;
	}
}

void	apply_d_f_plus(t_options *options_check, t_arrayList *arraylist)
{
	int	removed_count;

	removed_count = 0;
	if (ft_strchr(arraylist->data, '-'))
		return ;
	if (options_check->flag_minus == SWITCH_ON)
	{
		if (al_get(arraylist, arraylist->size - 1) == ' ')
			al_remove_back(arraylist);
		al_insert_front(arraylist, '+');
		return ;
	}
	apply_d_f_switch(options_check, arraylist);
	while (al_get(arraylist, 0) == ' ')
	{
		al_remove_front(arraylist);
		removed_count++;
	}
	al_insert_front(arraylist, '+');
	removed_count--;
	while (removed_count-- > 0)
		al_insert_front(arraylist, ' ');
}
