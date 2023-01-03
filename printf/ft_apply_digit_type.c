/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_digit_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:39:13 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/03 20:39:34 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_digit_number_for_hexadecimal(int decimal)
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

char	*decimal_to_string(int decimal)
{
	char	*result;
	
	result = ft_itoa(decimal);
	return (result);
}

char	*decimal_to_string_nosign(int decimal)
{
	char	*result;
	
	if (decimal < 0)
		decimal *= -1;
	result = ft_itoa(decimal);
	return (result);
}

char	*decimal_to_lowcase_hexadecimal(int decimal)
{
	char	*result;
	int		digit_number;

	digit_number = count_digit_number_for_hexadecimal(decimal);
	result[digit_number] = '\0';
	digit_number--;
	while (decimal > 0)
	{
		result[digit_number] = "0123456789abcdef"[decimal % 16];
		decimal /= 16;
		digit_number--;
	}
	return (result);
}

char	*decimal_to_uppercase_hexadecimal(int decimal)
{
	char	*result;
	int		digit_number;

	digit_number = count_digit_number_for_hexadecimal(decimal);
	result[digit_number] = '\0';
	digit_number--;
	while (decimal > 0)
	{
		result[digit_number] = "0123456789ABCDEF"[decimal % 16];
		decimal /= 16;
		digit_number--;
	}
	return (result);
}