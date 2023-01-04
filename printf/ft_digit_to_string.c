/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:39:13 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/04 19:43:41 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_decimal_to_string(int decimal)
{
	char	*result;
	
	result = ft_itoa(decimal);
	return (result);
}

char	*ft_decimal_to_string_nosign(int decimal)
{
	char	*result;
	
	if (decimal < 0)
		decimal *= -1;
	result = ft_itoa(decimal);
	return (result);
}

char	*ft_decimal_to_lowcase_hexadecimal(int decimal)
{
	char	*result;
	int		digit_number;

	digit_number = ft_count_digit_number(decimal);
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

char	*ft_decimal_to_uppercase_hexadecimal(int decimal)
{
	char	*result;
	int		digit_number;

	digit_number = ft_count_digit_number(decimal);
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

char	*ft_pointer_to_uppercase_hexadecimal(unsigned long long decimal)
{
	char	*result;
	int		digit_number;

	digit_number = count_digit_number_for_ull(decimal) + 2;
	result[digit_number] = '\0';
	digit_number--;
	while (decimal > 0)
	{
		result[digit_number] = "0123456789ABCDEF"[decimal % 16];
		decimal /= 16;
		digit_number--;
	}
	result[digit_number] = 'X';
	digit_number--;
	result[digit_number] = 'O'; 
	return (result);
}