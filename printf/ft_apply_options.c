/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:18:56 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/04 20:42:16 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_apply_precision(options *string_info)
{
	char *string;

	if (string_info->precision_have == 0)
		return ;
	ft_new_string(string, string_info->precision + 1);
	ft_strlcpy(string, (const char)(string_info->value), (string_info->precision) + 1);
	string_info->value = string;
	free(string);
}

void ft_apply_width(options *string_info)
{
	char	*string;
	int		strlen;
	int		copy_len;

	if (string_info->width_have == 0)
		return ;
	strlen = ft_strlen(string_info->value);
	ft_new_string(string, string_info->width + 1);
	ft_memset(string, ' ', string_info->width + 1);
	copy_len = string_info->width - strlen;
	if (copy_len > 0)
	{
		ft_strlcpy(string + copy_len, string_info->value, strlen);
		string_info->value = string;
	}
	free(string);
}

void ft_apply_flag(options* string_info)
{
	ft_apply_flag_minus(string_info);
	ft_apply_flag_plus(string_info);
	ft_apply_flag_space(string_info);
	ft_apply_flag_zero(string_info);
	ft_apply_flag_hash(string_info);
}
