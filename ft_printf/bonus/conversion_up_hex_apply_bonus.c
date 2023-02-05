/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_up_hex_apply_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:04:48 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/30 19:43:49 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	put_upper_hex_to_al(unsigned int up_hex_arg, t_arrayList *arraylist)
{
	char	*upper_hex_str;
	int		i;

	upper_hex_str = ft_uitoa(up_hex_arg);
	i = 0;
	while (upper_hex_str[i])
	{
		al_insert_back(arraylist, upper_hex_str[i]);
		i++;
	}
	free(upper_hex_str);
}

void	apply_up_hex_hash(t_options *options_check, t_arrayList *arraylist)
{
	if (options_check->width >= ft_strlen(options_check->str))
	{
		while (al_get(arraylist, 0) == ' ')
			al_remove_front(arraylist);
		al_insert_front(arraylist, 'X');
		al_insert_front(arraylist, '0');
		while (options_check->width > arraylist->size)
			al_insert_front(arraylist, ' ');
		return ;
	}
	al_insert_front(arraylist, 'X');
	al_insert_front(arraylist, '0');
}

void	apply_upper_hex(t_options *options_check, va_list *args, \
						t_arrayList *arraylist)
{
	unsigned int	up_hex_arg;

	up_hex_arg = va_arg(*args, unsigned int);
	put_upper_hex_to_al(up_hex_arg, arraylist);
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
		!(arraylist->size == 0))
		apply_up_hex_hash(options_check, arraylist);
}
