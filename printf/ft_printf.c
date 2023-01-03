/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:54:10 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/03 20:46:54 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent_or_other(char c)
{
	if (c == '%')
		return (1);
	else if (c == 92)  // 역슬래시
		return (2);
	else if (32 < c && c < 126)
		return (3);
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
	string_info->width = -1;
	c = *(format + *(index));
	if ((c < 0) || (c > 9))
		return ;
	while ((c >= 0) && (c <= 9))
    {
		num *= 10;
		num += (c - '0');
		(*index)++;
		c = *(format + *(index));
    }
	string_info->width = num;
	// 오버플로우 또는 언더플로우의 경우에는 -1 or 0
	// 
}

void	ft_precision_check(const char *format, size_t *index, options *string_info)
{
	int num;
	char c;

	num = 0;
	string_info->precision = -1;
	c = *(format + *(index));
	if ((c < 0) || (c > 9))
		return ;
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

int	ft_conversion(const char *format, size_t *index, options *string_info)
{
	ft_memset(string_info, 0, sizeof(options));
	while (ft_flag_checker(*(format + *(index))))
	{
		ft_flag_check(*(format + *(index)), string_info);
		(*index)++;
	}
	ft_width_check(format, index, string_info);
	if (*(format + *(index)) == '.')
		(*index)++;
	ft_precision_check(format, index, string_info);
	if (ft_type_checker(*(format + *(index))) == 0)
		return (-1);
	string_info->type = *(format + *(index));
	// print
	return (0);
}

int ft_apply_int(options *string_info, int value)
{
	// 구조체에 적용됩 옵션들을 인자값에 적용
}

int ft_apply_percent(options *string_info, char value)
{

}

char *ft_apply_string(options *string_info, char *value)
{

}

char *ft_apply_pointer(options *string_info, unsigned long long value)
{

}

int ft_printf(const char *format, ...)
{
	size_t	index;
	va_list	ap;
	options *string_info;
	
	index = 0;
	string_info = (options *)malloc(sizeof(options));
	va_start(ap, format); // format 다음 주소부터 시작
	while (*(format + index))
	{
		if (ft_percent_or_other(*(format + index)) == 1) // %인 경우
		{
			if (ft_conversion(format, &index, string_info) == -1)
				return (-1); //구조체에 type 정리, 오류 처리
			if (ft_type_checker(string_info->type) == 1)
				ft_apply_int(string_info, va_arg(ap, int));
			else if (ft_type_checker(string_info->type) == 2)
				ft_apply_percent(string_info, '%');
			else if (ft_type_checker(string_info->type) == 3)
				ft_apply_string(string_info, va_arg(ap, char *));
			else if (ft_type_checker(string_info->type) == 4)
				ft_apply_pointer(string_info, va_arg(ap, unsigned long long));
		}
		else if (ft_percent_or_other(*(format + index)) == 2) // \인 경우
		{
			
		}
		
	}
	// va_arg(ap, int) // int값만큼 값을 읽어옴
	// ex) char *string;
	// string = va_arg(ap, char *)  --> 시작부터 char*만큼 받아옴
	// va_end : 끝
	// 바이트패딩 
}

#include <stdio.h>
int main()
{
	printf("fff\12");
}