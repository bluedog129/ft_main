/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:15:31 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/03 16:04:36 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char	*decimal_to_string(int decimal)
{
	char	*result;
	
	result = ft_itoa(decimal);
	return (result);
}

char	*decimal_to_string_nosign(int decimal)
{
	char	*result;
	
	if (decimal < 0)
		decimal *= -1;
	result = ft_itoa(decimal);
	return (result);
}

char	*