/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:58:21 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/04 19:27:52 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent_or_other(char c)
{
	if (c == '%')
		return (1);
	else if (32 < c && c < 126)
		return (2);
	return (-1);
}

int ft_flag_checker(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

void	ft_flag_check(char c, options *string_info)
{
	if (c == '-')
		string_info->flag_minus = 1;
	else if (c == '+')
		string_info->flag_plus = 1;
	else if (c == ' ')
		string_info->flag_space = 1;
	else if (c == '0')
		string_info->flag_zero = 1;
	else if (c == '#')
		string_info->flag_hash = 1;
}

void	ft_width_check(const char *format, size_t *index, options *string_info)
{
	int num;
	char c;

	num = 0;
	c = *(format + (*index));
	if ((c < '0') || (c > '9'))
		return ;
	while ((c >= '0') && (c <= '9'))
    {
		num *= 10;
		num += (c - '0');
		(*index)++;
		c = *(format + *(index));
    }
	string_info->width_have = 1;
	string_info->width = num;
	// 오버플로우 또는 언더플로우의 경우에는 -1 or 0
	// 
}

void	ft_precision_check(const char *format, size_t *index, options *string_info)
{
	int num;
	char c;

	num = 0;
	c = *(format + (*index));
	if ((c < '0') || (c > '9'))
		return ;
	while ((c >= '0') && (c <= '9'))
    {
		num *= 10;
		num += (c - '0');
		(*index)++;
		c = *(format + (*index));
    }
	string_info->precision_have = 1;
	string_info->precision = num;
}
