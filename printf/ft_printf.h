/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:13:25 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/03 20:45:17 by hyojocho         ###   ########.fr       */
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
void	ft_flag_check(char c, options *string_info)
void	ft_width_check(const char *format, size_t *index, options *string_info);
void	ft_precision_check(const char *format, size_t *index, options *string_info);
int 	ft_type_checker(char c);
int		ft_conversion(const char *format, size_t *index, options *string_info);
int 	ft_print_backslash(const char *format, int *index)

char	*decimal_to_string(int decimal);
char	*decimal_to_string_nosign(int decimal);
char	*decimal_to_lowcase_hexadecimal(int decimal);
char	*decimal_to_uppercase_hexadecimal(int decimal);





#endif