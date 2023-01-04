/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:53:46 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/04 20:12:28 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_apply_int(options *string_info, int value)
{
	char *string;

	if (string_info->type == 'd' || (string_info->type == 'i')\
	|| (string_info->type == 'u'))
		string_info->value = ft_decimal_to_string(value);
	if (string_info->type == 'x')
		string_info->value = ft_decimal_to_lowcase_hexadecimal(value);
	if (string_info->type == 'X')
		string_info->value = ft_decimal_to_uppercase_hexadecimal(value);
	if (string_info->type == 'c')
	{
		string_info->value = ft_memset(string, (char)value, 1);
		string_info->value = ft_memset(string + 1, '\0', 1);
	}
}

void ft_apply_percent(options *string_info, char value)
{
	char *string;

	string_info->value = ft_memset(string, (char)value, 1);
	string_info->value = ft_memset(string + 1, '\0', 1);
}

void ft_apply_string(options *string_info, char *value)
{
	string_info->value = value;
}

void ft_apply_pointer(options *string_info, unsigned long long value)
{
	string_info->value = ft_pointer_to_uppercase_hexadecimal(value);
}

void ft_apply_option(va_list ap, options *string_info)
{
	if (ft_type_checker(string_info->type) == 1)
		ft_apply_int(string_info, va_arg(ap, int));
	else if (ft_type_checker(string_info->type) == 2)
		ft_apply_percent(string_info, '%');
	else if (ft_type_checker(string_info->type) == 3)
		ft_apply_string(string_info, va_arg(ap, char *));
	else if (ft_type_checker(string_info->type) == 4)
		ft_apply_pointer(string_info, va_arg(ap, unsigned long long));
	ft_apply_precision(string_info);
	ft_apply_width(string_info);
	ft_apply_flag(string_info);
}
