/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:53:07 by minkim3           #+#    #+#             */
/*   Updated: 2023/01/04 20:13:16 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
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
	int width_have;
	int precision;
	int precision_have;
	int type;
	char *value;
} options;

//ft_check_options.c
int		ft_percent_or_other(char c);
int 	ft_flag_checker(char c);
void	ft_flag_check(char c, options *string_info);
void	ft_width_check(const char *format, size_t *index, options *string_info);
void	ft_precision_check(const char *format, size_t *index, options *string_info);

//ft_conversion.c
int		ft_option_error(options *string_info);
int		ft_conversion(const char *format, size_t *index, options *string_info);
int		ft_error(void);
int 	ft_type_checker(char c);
int		ft_count_digit_number(int decimal);

// ft_digit_to_string.c 
char	*ft_decimal_to_string(int decimal);
char	*ft_decimal_to_string_nosign(int decimal);
char	*ft_decimal_to_lowcase_hexadecimal(int decimal);
char	*ft_decimal_to_uppercase_hexadecimal(int decimal);
char	*ft_pointer_to_uppercase_hexadecimal(unsigned long long decimal);

// ft_apply_type.c
void	ft_apply_int(options *string_info, int value);
void	ft_apply_percent(options *string_info, char value);
void	ft_apply_string(options *string_info, char *value);
void	ft_apply_pointer(options *string_info, unsigned long long value);
void	ft_apply_option(va_list ap, options *string_info);

// ft_apply_options.c
void	ft_apply_precision(options *string_info);
void	ft_apply_width(options *string_info);
void	ft_apply_flag(options* string_info);

//ft_apply_flags.c
void	ft_apply_flag_minus(options* string_info);
void	ft_apply_flag_plus(options* string_info);
void	ft_apply_flag_space(options* string_info);
void	ft_apply_flag_zero(options* string_info);
void	ft_apply_flag_hash(options* string_info);


#endif