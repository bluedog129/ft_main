/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:47:31 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/04 13:47:32 by hyojocho         ###   ########.fr       */
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

void ft_apply_type(va_list ap, options *string_info)
{
	if (ft_type_checker(string_info->type) == 1)
		ft_apply_int(string_info, va_arg(ap, int));
	else if (ft_type_checker(string_info->type) == 2)
		ft_apply_percent(string_info, '%');
	else if (ft_type_checker(string_info->type) == 3)
		ft_apply_string(string_info, va_arg(ap, char *));
	else if (ft_type_checker(string_info->type) == 4)
		ft_apply_pointer(string_info, va_arg(ap, unsigned long long));
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
			ft_apply_type(ap, string_info);
		}
		else if (ft_percent_or_other(*(format + index)) == 2) // 출력 가능한 문자인 경우
			write(1, &*(format + index), 1);
	}
	free(string_info);
	va_end(ap);
}

#include <stdio.h>
int main()
{
	printf("fff\12");
}