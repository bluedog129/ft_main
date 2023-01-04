/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:13:25 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/04 13:42:25 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct options_type{
	int flag_minus;
	int flag_plus;
	int flag_space;
	int flag_zero;
	int flag_hash;
	int width;
	int precision;
	int type;
} options;



#endif