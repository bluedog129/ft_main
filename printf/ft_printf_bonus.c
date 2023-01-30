/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:21:11 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/30 19:44:13 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	check_format(const char format)
{
	if (format == '%')
		return (PLACEHOLDER);
	else
		return (NOT_PLACEHOLDER);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_width;
	int		placeholder_width;

	placeholder_width = 0;
	total_width = 0;
	va_start(args, format);
	while (*format)
	{
		if (check_format(*format) == PLACEHOLDER)
		{
			format++;
			placeholder_width = parse_format_placehoder_syntax(&format, &args);
			if (placeholder_width == ERROR)
				return (ERROR);
			total_width += placeholder_width;
		}
		else if (check_format(*format) == NOT_PLACEHOLDER)
			total_width += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (total_width);
}
