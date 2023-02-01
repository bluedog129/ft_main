/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:13:25 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/30 20:41:34 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include "libft/libft.h"
# include "ft_arraylist_bonus.h"

enum e_format_check {
	NOT_PLACEHOLDER = 1,
	PLACEHOLDER = 2,
	ERROR = -1
};

enum e_flag_check {
	SWITCH_OFF = 0,
	SWITCH_ON = 1,
	FLAG_CHk_ALLOC_ERROR = -1
};

enum e_conversion_check {
	PERCENT = '%',
	CHARACTER = 'c',
	STRING = 's',
	DECIMAL_D = 'd',
	DECIMAL_I = 'i',
	UNSIGNED_DECIMAL = 'u',
	POINTER = 'p',
	UPPER_HEX = 'X',
	LOWER_HEX = 'x'
};

enum e_sign {
	SIGN_MINUS = -1,
	SIGN_NULL = 0,
	SIGN_PLUS = 1,
	SIGN_HEX = 2
};

typedef struct options_type {
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_zero;
	int		flag_hash;
	int		width;
	int		width_switch;
	int		precision;
	int		precision_switch;
	char	conversion;
	char	*space_or_zero;
	char	*str;
	int		arg;
	int		str_len;
	char	*minus_or_space;
}	t_options;

int		parse_format_placehoder_syntax(const char **format, va_list *args);
int		ft_printf(const char *format, ...);
int		check_format(const char format);
void	check_options(const char **format, t_options *options_check);
void	check_conversion(const char *format, t_options *options_check);
void	apply_conversion(t_options *options_check, \
						va_list *args, t_arrayList *arraylist);
int		app_op_and_conv(t_options *options_check, va_list *args);
void	apply_character(t_options *options_check, va_list *args, \
						t_arrayList *arraylist);
void	apply_string(t_options *options_check, va_list *args, \
					t_arrayList *arraylist);
void	get_width(const char format, t_options *options_check);
void	get_precision(const char **format, t_options *options_check);
void	apply_percent(t_options *options_check, t_arrayList *arraylist);
void	apply_percent_width(t_options *options_check, t_arrayList *arraylist);
void	apply_percent_f_minus(t_options *options_check, t_arrayList *arraylist);
void	apply_percent_f_zero(t_options *options_check, t_arrayList *arraylist);
void	apply_str_precision(t_options *options_check, t_arrayList *arraylist);
void	apply_str_width(t_options *options_check, t_arrayList *arraylist);
void	apply_str_f_minus(t_options *options_check, t_arrayList *arraylist);
void	apply_d(t_options *options_check, va_list *args, \
		t_arrayList *arraylist);
void	apply_du_precision(t_options *options_check, t_arrayList *arraylist);
void	apply_dp_width(t_options *options_check, t_arrayList *arraylist);
void	apply_dp_f_minus(t_options *options_check, t_arrayList *arraylist);
void	apply_d_f_zero(t_options *options_check, t_arrayList *arraylist);
void	apply_d_f_space(t_options *options_check, t_arrayList *arraylist);
void	apply_d_f_plus(t_options *options_check, t_arrayList *arraylist);
void	apply_pointer(t_options *options_check, va_list *args, \
		t_arrayList *arraylist);
void	put_pointer_to_al(unsigned long long hex_arg, t_arrayList *arraylist);
void	apply_unsigned_decimal(t_options *options_check, va_list *args, \
		t_arrayList *arraylist);
void	put_ud_to_al(unsigned int ui_arg, t_arrayList *arraylist);
void	apply_upper_hex(t_options *options_check, va_list *args, \
		t_arrayList *arraylist);
void	put_upper_hex_to_al(unsigned int up_hex_arg, t_arrayList *arraylist);
void	apply_up_hex_hash(t_options *options_check, t_arrayList *arraylist);
void	apply_lower_hex(t_options *options_check, va_list *args, \
		t_arrayList *arraylist);
void	put_lower_hex_to_al(unsigned int low_hex_arg, t_arrayList *arraylist);
void	apply_low_hex_hash(t_options *options_check, t_arrayList *arraylist);

#endif