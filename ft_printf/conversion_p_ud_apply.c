/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p_ud_apply.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:58:40 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/30 19:03:13 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_pointer_to_al(unsigned long long hex_arg, t_arrayList *arraylist)
{
	char	*pointer_str;
	int		i;

	al_insert_back(arraylist, '0');
	al_insert_back(arraylist, 'x');
	pointer_str = ft_htoa(hex_arg);
	i = 0;
	while (pointer_str[i])
	{
		al_insert_back(arraylist, pointer_str[i]);
		i++;
	}
	free(pointer_str);
}

void	apply_pointer(t_options *options_check, va_list *args, \
		t_arrayList *arraylist)
{
	unsigned long long	pointer_arg;

	pointer_arg = va_arg(*args, unsigned long long);
	put_pointer_to_al(pointer_arg, arraylist);
	if (options_check->width_switch == SWITCH_ON)
		apply_dp_width(options_check, arraylist);
	if (options_check->flag_minus == SWITCH_ON)
		apply_dp_f_minus(options_check, arraylist);
}

void	put_ud_to_al(unsigned int ui_arg, t_arrayList *arraylist)
{
	char	*ud_str;
	int		i;

	ud_str = ft_utoa(ui_arg);
	i = 0;
	while (ud_str[i])
	{
		al_insert_back(arraylist, ud_str[i]);
		i++;
	}
	free(ud_str);
}

void	apply_unsigned_decimal(t_options *options_check, va_list *args, \
		t_arrayList *arraylist)
{
	unsigned int	ui_arg;

	ui_arg = va_arg(*args, unsigned int);
	put_ud_to_al(ui_arg, arraylist);
	if (options_check->precision_switch == SWITCH_ON)
		apply_du_precision(options_check, arraylist);
	if (options_check->width_switch == SWITCH_ON)
		apply_dp_width(options_check, arraylist);
	if (options_check->flag_minus == SWITCH_ON)
		apply_dp_f_minus(options_check, arraylist);
	if (options_check->flag_zero == SWITCH_ON && \
		options_check->precision_switch == SWITCH_OFF)
		apply_d_f_zero(options_check, arraylist);
}
