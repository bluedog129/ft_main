/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:05:42 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/04 14:58:43 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	apply_flag_minus(char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	
}

void	apply_flag_plus(char *str)
{
	int		converted_int;
	char	*converted_str;
	
	converted_int = ft_itoa(str);
	converted_str = ft_atoi(converted_int);
	return (converted_str);
}

