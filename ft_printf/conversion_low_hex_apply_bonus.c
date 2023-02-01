/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_low_hex_apply_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:08:37 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/30 19:43:40 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	apply_low_hex_hash(t_options *options_check, t_arrayList *arraylist)
{
	if (options_check->width >= ft_strlen(options_check->str))
	{
		while (al_get(arraylist, 0) == ' ')
			al_remove_front(arraylist);
		al_insert_front(arraylist, 'x');
		al_insert_front(arraylist, '0');
		while (options_check->width > arraylist->size)
			al_insert_front(arraylist, ' ');
		return ;
	}
	al_insert_front(arraylist, 'x');
	al_insert_front(arraylist, '0');
}

void	put_lower_hex_to_al(unsigned int low_hex_arg, t_arrayList *arraylist)
{
	char	*lower_hex_str;
	int		i;

	lower_hex_str = ft_uitoa_lower(low_hex_arg);
	i = 0;
	while (lower_hex_str[i])
	{
		al_insert_back(arraylist, lower_hex_str[i]);
		i++;
	}
	free(lower_hex_str);
}

void	apply_lower_hex(t_options *options_check, va_list *args, \
						t_arrayList *arraylist)
{
	unsigned int	low_hex_arg;

	low_hex_arg = va_arg(*args, unsigned int);
	put_lower_hex_to_al(low_hex_arg, arraylist);
	options_check->str = arraylist->data;
	if (options_check->precision_switch == SWITCH_ON)
		apply_du_precision(options_check, arraylist);
	if (options_check->width_switch == SWITCH_ON)
		apply_dp_width(options_check, arraylist);
	if (options_check->flag_minus == SWITCH_ON)
		apply_dp_f_minus(options_check, arraylist);
	if (options_check->flag_zero == SWITCH_ON && \
		options_check->precision_switch == SWITCH_OFF)
		apply_d_f_zero(options_check, arraylist);
	if (options_check->flag_hash == SWITCH_ON && \
		!(arraylist->size == 1 && al_get(arraylist, 0) == '0') && \
		!(arraylist->size == 0) && low_hex_arg != 0)
		apply_low_hex_hash(options_check, arraylist);
}
