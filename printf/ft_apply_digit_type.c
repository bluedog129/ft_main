/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_digit_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:15:31 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/04 15:07:54 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_digit_number(int decimal)
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

int		count_digit_number_ull(int decimal)
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

	digit_number = count_digit_number(decimal);
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

	digit_number = count_digit_number(decimal);
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

char	*voidpointer_to_uppercase_hexadecimal(unsigned long long decimal)
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