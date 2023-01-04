/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:26:44 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/04 20:12:27 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_type_checker(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'c')
		return (1);  // 인자가 숫자
	else if (c == '%')
		return (2);  // % 인자 안받음
	else if (c == 's')
		return (3);  // s는 char *
	else if (c == 'p')
		return (4);  // p는 unsigned long long
	return (0);
}

int ft_option_error(options *string_info)
{
	if (string_info->type == 'c' || string_info->type == 'p')
		if (string_info->precision_have == 1 || string_info->flag_zero == 1\
		|| string_info->flag_hash == 1 || string_info->flag_space == 1\
		|| string_info->flag_plus == 1)
			ft_error();
	if (string_info->type == 'c' || string_info->type == 's'\
	|| string_info->type == 'p' || string_info->type == '%')
		if (string_info->flag_zero == 1 || string_info->flag_hash == 1\
		 || string_info->flag_space == 1 || string_info->flag_plus == 1)
		 ft_error();
	if (string_info->type == 'd' || string_info->type == 'i'\
	|| string_info->type == 'u')
		if (string_info->flag_hash == 1)
			ft_error();
	if (string_info->type == 'u' || string_info->type == 'x'\
	|| string_info->type == 'X')
		if (string_info->flag_space == 1 || string_info->flag_plus == 1)
			ft_error();
	return (0);
}

int	ft_conversion(const char *format, size_t *index, options *string_info)
{
	ft_memset(string_info, 0, sizeof(options));
	while (ft_flag_checker(*(format + (*index))))  //flag check
	{
		ft_flag_check(*(format + (*index)), string_info);
		(*index)++;
	}
	ft_width_check(format, index, string_info);  // width check
	if (*(format + (*index)) == '.')
		(*index)++;
	ft_precision_check(format, index, string_info);  //precision check
	if (ft_type_checker(*(format + (*index))) == 0)  // type check
		return (-1);
	string_info->type = *(format + (*index));
	if (string_info->flag_zero == 1 && string_info->flag_minus == 1)
		return (-1);  // -0 flag 불가능
	return (ft_option_error(string_info));
}

int ft_error(void)
{
	write(1, "-1", 2);
	return (-1);
}

int		ft_count_digit_number(int decimal)
{
	int digit_number;

	digit_number = 0;
	while (decimal > 0)
	{
		decimal /= 16;
		digit_number++;
	}
	return (digit_number);
}
