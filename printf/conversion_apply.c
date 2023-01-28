/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_apply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:02:04 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/28 19:46:15 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_percent(t_options *options_check, t_arrayList *arraylist)
{
	al_insert_back(arraylist, '%');
	if (options_check->width_switch == SWITCH_ON)
		apply_percent_width(options_check, arraylist);
	if (options_check->flag_minus == SWITCH_ON)
		apply_percent_f_minus(options_check, arraylist);
	if (options_check->flag_zero == SWITCH_ON)
		apply_percent_f_zero(options_check, arraylist);
}

void	apply_character(t_options *options_check, va_list *args, \
						t_arrayList *arraylist)
{
	char	result;
	int		space_len;

	space_len = 0;
	result = va_arg(*args, size_t);
	if (options_check->width > 0)
		space_len = options_check->width - 1;
	if (options_check->flag_minus)
	{
		al_insert_back(arraylist, result);
		while (space_len--)
			al_insert_back(arraylist, ' ');
		return ;
	}
	while (space_len--)
		al_insert_back(arraylist, ' ');
	al_insert_back(arraylist, result);
}

void	apply_string(t_options *options_check, va_list *args, \
					t_arrayList *arraylist)
{
	int	i;
	int	str_len;

	options_check->str = va_arg(*args, char *);
	if (options_check->str == NULL)
		options_check->str = "(null)";
	str_len = ft_strlen(options_check->str);
	i = 0;
	while (str_len--)
		al_insert_back(arraylist, options_check->str[i++]);
	if (options_check->precision_switch)
		apply_str_precision(options_check, arraylist);
	if (options_check->width_switch)
		apply_str_width(options_check, arraylist);
	if (options_check->flag_minus)
		apply_str_f_minus(options_check, arraylist);
}

void	put_decimal_to_al(int decimal_arg, t_arrayList *arraylist)
{
	char	*decimal_str;
	int		i;
	
	decimal_str = ft_itoa(decimal_arg);
	i = 0;
	while (decimal_str[i])
	{
		al_insert_back(arraylist, decimal_str[i]);
		i++;
	}
	free(decimal_str);
}

void	apply_d(t_options *options_check, va_list *args, t_arrayList *arraylist)
{
	int	decimal_arg;
	
	decimal_arg = va_arg(*args, int);
	put_decimal_to_al(decimal_arg, arraylist);
	if (options_check->precision_switch == SWITCH_ON)
		apply_du_precision(options_check, arraylist);
	// printf("precision : \n%s\n", arraylist->data);
	if (options_check->width_switch == SWITCH_ON)
		apply_dp_width(options_check, arraylist);
	// printf("apply_dp_width : \n%s\n", arraylist->data);
	if (options_check->flag_minus == SWITCH_ON)
		apply_dp_f_minus(options_check, arraylist);
	// printf("apply_dp_f_minus : \n%s\n", arraylist->data);
	if (options_check->flag_zero == SWITCH_ON && \
		options_check->precision_switch == SWITCH_OFF)
		apply_d_f_zero(options_check, arraylist);
	// printf("apply_d_f_zero : \n%s\n", arraylist->data);
	if (options_check->flag_space == SWITCH_ON && \
		options_check->flag_plus == SWITCH_OFF)
		apply_d_f_space(options_check, arraylist);
	// printf("apply_d_f_space : \n%s\n", arraylist->data);
	if (options_check->flag_plus == SWITCH_ON && \
		options_check->flag_space == SWITCH_OFF)
		apply_d_f_plus(options_check, arraylist);
	// printf("apply_d_f_plus : \n%s\n", arraylist->data);
}

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

void	apply_pointer(t_options *options_check, va_list *args, t_arrayList *arraylist)
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

void	apply_unsigned_decimal(t_options *options_check, va_list *args, t_arrayList *arraylist)
{
	unsigned int	ui_arg;

	ui_arg = va_arg(*args, unsigned int);
	put_ud_to_al(ui_arg, arraylist);
	if (options_check->precision_switch == SWITCH_ON)
		apply_du_precision(options_check, arraylist);
	if (options_check->width_switch == SWITCH_ON)
		apply_dp_width(options_check, arraylist);
}