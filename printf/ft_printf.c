/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:54:10 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/03 20:58:53 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

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
		if (ft_percent_or_other(*(format + index)) == -1) // 오류
			ft_error();
		if (ft_percent_or_other(*(format + index)) == 1) // %인 경우
		{
			if (ft_conversion(format, &index, string_info) == -1)
				ft_error(); //구조체에 type 정리, 오류 처리
			if (ft_type_checker(string_info->type) == 1)
				ft_apply_int(string_info, va_arg(ap, int));
			else if (ft_type_checker(string_info->type) == 2)
				ft_apply_percent(string_info, '%');
			else if (ft_type_checker(string_info->type) == 3)
				ft_apply_string(string_info, va_arg(ap, char *));
			else if (ft_type_checker(string_info->type) == 4)
				ft_apply_pointer(string_info, va_arg(ap, unsigned long long));
		}
		else if (ft_percent_or_other(*(format + index)) == 2) // 출력 가능한 문자인 경우
			write(1, &*(format + index), 1);
	}
	// va_arg(ap, int) // int값만큼 값을 읽어옴
	// ex) char *string;
	// string = va_arg(ap, char *)  --> 시작부터 char*만큼 받아옴
	// va_end : 끝
	// 바이트패딩 
	va_end(ap);
}

#include <stdio.h>
int main()
{
	printf("fff\12");
}
