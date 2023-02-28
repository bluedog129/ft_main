/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_apply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:58:58 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/30 18:48:23 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_precision(const char **format, t_options *options_check)
{
	(*format)++;
	options_check->precision_switch = SWITCH_ON;
	while ('0' <= **format && **format <= '9')
	{
		options_check->precision *= 10;
		options_check->precision += (**format - '0');
		(*format)++;
	}
}

void	apply_str_precision(t_options *options_check, t_arrayList *arraylist)
{
	int	result_len;
	int	i;

	al_reset(arraylist);
	result_len = ft_strlen(options_check->str);
	if (options_check->precision < result_len)
		result_len = options_check->precision;
	i = 0;
	while (result_len--)
	{
		al_insert_back(arraylist, options_check->str[i]);
		i++;
	}
}

void	apply_du_precision(t_options *options_check, t_arrayList *arraylist)
{
	int	str_len;
	int	precision_len;

	str_len = arraylist->size;
	if (arraylist->data[0] == '0' && options_check->precision == 0)
		al_remove_front(arraylist);
	if (al_get(arraylist, 0) == '-')
	{
		str_len = arraylist->size - 1;
		precision_len = options_check->precision - str_len;
		al_remove_front(arraylist);
		while (precision_len-- > 0)
			al_insert_front(arraylist, '0');
		al_insert_front(arraylist, '-');
		return ;
	}
	if (options_check->precision > str_len)
	{
		precision_len = options_check->precision - str_len;
		while (precision_len-- > 0)
			al_insert_front(arraylist, '0');
	}
}
