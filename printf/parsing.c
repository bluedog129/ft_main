/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:47:43 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/28 19:44:40 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_options(const char **format, t_options *options_check)
{
	while (ft_strchr("-+ #0", **format))
	{
		if (**format == '-')
			options_check->flag_minus = SWITCH_ON;
		else if (**format == '+')
			options_check->flag_plus = SWITCH_ON;
		else if (**format == ' ')
			options_check->flag_space = SWITCH_ON;
		else if (**format == '#')
			options_check->flag_hash = SWITCH_ON;
		else if (**format == '0')
			options_check->flag_zero = SWITCH_ON;
		(*format)++;
	}
	while (ft_isdigit(**format))
	{
		get_width(**format, options_check);
		(*format)++;
	}
	if (ft_strchr(".", **format))
		get_precision(format, options_check);
}

void	check_conversion(const char *format, t_options *options_check)
{
	if (*format == '%')
		options_check->conversion = PERCENT;
	else if (*format == 'c')
		options_check->conversion = CHARACTER;
	else if (*format == 's')
		options_check->conversion = STRING;
	else if (*format == 'd')
		options_check->conversion = DECIMAL_D;
	else if (*format == 'i')
		options_check->conversion = DECIMAL_I;
	else if (*format == 'u')
		options_check->conversion = UNSIGNED_DECIMAL;
	else if (*format == 'p')
		options_check->conversion = POINTER;
	else if (*format == 'x')
		options_check->conversion = LOWER_HEX;
	else if (*format == 'X')
		options_check->conversion = UPPER_HEX;
	format++;
}

int	parse_format_placehoder_syntax(const char **format, va_list *args)
{
	int			syntax_len;
	t_options	*options_check;

	options_check = (t_options *)malloc(sizeof(t_options));
	if (options_check == NULL)
		return (FLAG_CHk_ALLOC_ERROR);
	ft_memset(options_check, SWITCH_OFF, sizeof(t_options));
	check_options(format, options_check);
	if (ft_strchr("csdiupxX%", **format) == NULL)
		return (-1);
	check_conversion(*format, options_check);
	syntax_len = app_op_and_conv(options_check, args);
	free(options_check);
	return (syntax_len);
}
