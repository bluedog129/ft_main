/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:54:10 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/03 18:59:20 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_percent_or_other(char c)
{
	if (c == '%')
		return (1);
	else if (32 < c < 126)
		return (0);
	return (-1);
}

int ft_flag_checker(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}
int	ft_flag_check(char c, options *string_info)
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
	c = *(format + *(index));
	while ((c >= 0) && (c <= 9))
    {
		num *= 10;
		num += (c - '0');
		(*index)++;
		c = *(format + *(index));
    }
	string_info->width = num;
}

void	ft_precision_check(const char *format, size_t *index, options *string_info)
{
	int num;
	char c;

	num = 0;
	c = *(format + *(index));
	while ((c >= 0) && (c <= 9))
    {
		num *= 10;
		num += (c - '0');
		(*index)++;
		c = *(format + *(index));
    }
	string_info->precision = num;
}

int ft_type_checker(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' \
	|| c == '%' || c == 's' )
		return (1);
	return (0);
}

int	ft_conversion(const char *format, size_t *index)
{
	options *string_info;
	
	string_info = (options *)malloc(sizeof(options));
	ft_memset(string_info, 0, sizeof(options));
	while (ft_flag_checker(*(format + *(index))))
	{
		ft_flag_check(*(format + *(index)), string_info);
		*(index)++;
	}
	ft_width_check(format, index, string_info);
	if (*(format + *(index)) == '.')
		*(index)++;
	ft_precision_check(format, index, string_info);
	if (ft_type_checker(*(format + *(index))) == 1)
	{
		string_info->type = *(format + *(index));
		return (0);
	}
	else
		return (-1);
}

char *ft_apply_option(인자, 구조체)
{
	// 구조체에 적용됩 옵션들을 인자값에 적용
}

char *ft_print_number_d()
{

}


int ft_printf(const char *format, ...)
{
	size_t	index;
	size_t	length;

	index = 0;
	while (*(format + index))
	{
		if (ft_percent_or_other(*(format + index)) == 1)
		{
			if (ft_conversion(format, &index) == -1)
				return (-1); //구조체에 type 정리, 오류 처리
		}
		
	}
	// 문자열이라면 버퍼에 추가
	// %가 나올 경우 변환	
}