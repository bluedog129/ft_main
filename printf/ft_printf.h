/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:53:07 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/03 21:23:00 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct options_type {
	int flag_minus;
	int flag_plus;
	int flag_space;
	int flag_zero;
	int flag_hash;
	int width;
	int precision;
	int type;
} options;


int		ft_percent_or_other(char c);
int 	ft_flag_checker(char c);
void	ft_flag_check(char c, options *string_info);
void	ft_width_check(const char *format, size_t *index, options *string_info);
void	ft_precision_check(const char *format, size_t *index, options *string_info);
int 	ft_type_checker(char c);
int		ft_conversion(const char *format, size_t *index, options *string_info);
int		ft_error(void);
int 	ft_print_backslash(const char *format, int *index);
void	ft_apply_type(va_list ap, options *string_info);


int		count_digit_number_for_hexadecimal(int decimal);
char	*decimal_to_string(int decimal);
char	*decimal_to_string_nosign(int decimal);
char	*decimal_to_lowcase_hexadecimal(int decimal);
char	*decimal_to_uppercase_hexadecimal(int decimal);





#endif