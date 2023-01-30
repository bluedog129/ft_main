/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_apply_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:18:51 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/30 19:44:34 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	get_width(const char format, t_options *options_check)
{
	options_check->width_switch = SWITCH_ON;
	options_check->width *= 10;
	options_check->width += (format - '0');
}

void	apply_percent_width(t_options *options_check, t_arrayList *arraylist)
{
	int	width_len;

	width_len = options_check->width - 1;
	while (width_len-- > 0)
		al_insert_front(arraylist, ' ');
}

void	apply_str_width(t_options *options_check, t_arrayList *arraylist)
{
	int		i;
	int		width_len;
	int		str_len;
	char	*pre_tmp;

	width_len = options_check->width;
	str_len = arraylist->size;
	options_check->str_len = str_len;
	if (options_check->width > arraylist->size)
	{
		al_reset(arraylist);
		width_len -= str_len;
		while (width_len--)
			al_insert_back(arraylist, ' ');
		i = 0;
		while (str_len--)
			al_insert_back(arraylist, options_check->str[i++]);
	}
}

void	apply_dp_width(t_options *options_check, t_arrayList *arraylist)
{
	int	width_len;
	int	str_len;

	width_len = options_check->width - arraylist->size;
	if (options_check->width > arraylist->size)
	{
		while (width_len-- > 0)
			al_insert_front(arraylist, ' ');
	}
}
