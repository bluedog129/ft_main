/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:31:31 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/26 17:50:24 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_conversion(t_options *options_check, va_list args, t_arrayList *arraylist)
{
	if (options_check->conversion == PERCENT)
		apply_percent(options_check, arraylist);
	else if (options_check->conversion == CHARACTER)
		apply_character(options_check, args, arraylist);
	else if (options_check->conversion == STRING)
		apply_string(options_check, args, arraylist);
	else if (options_check->conversion == DECIMAL_D || \
			options_check->conversion == DECIMAL_I)
		apply_d(options_check, args, arraylist);
	// else if (options_check->conversion == UNSIGNED_DECIMAL)
	// 	apply_unsigned_decimal();
	else if (options_check->conversion == POINTER)
		apply_pointer(options_check, args, arraylist);
	// else if (options_check->conversion == UPPER_HEX)
	// 	apply_upper_hex();
	// else if (options_check->conversion == LOWER_HEX)
	// 	apply_lower_hex();
}

int	app_op_and_conv(t_options *options_check, va_list args)
{
	t_arrayList	*arraylist;
	char		*result;
	int			result_len;

	arraylist = (t_arrayList *)malloc(sizeof(t_arrayList));
	if (arraylist == NULL)
		return (ERROR);
	ft_memset(arraylist, 0, sizeof(arraylist));
	al_init(arraylist);
	apply_conversion(options_check, args, arraylist);
	result_len = arraylist->size;
	result = arraylist->data;
	write(1, result, result_len);
	free(arraylist->data);
	free(arraylist);
	arraylist = NULL;
	return (result_len);
}
