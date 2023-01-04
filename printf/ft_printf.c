/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:54:10 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/04 20:33:44 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			ft_apply_option(ap, string_info);
		}
		else if (ft_percent_or_other(*(format + index)) == 2) // 출력 가능한 문자인 경우
			write(1, &*(format + index), 1);
		index++;
	}
	free(string_info);
	va_end(ap);
	return (0);
}
