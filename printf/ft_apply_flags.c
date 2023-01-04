/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:05:42 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/04 19:11:19 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*apply_flag_minus(char *str)
{
	int 	i;
	int		buff_index;
	char	*buff;

	i = 0;
	buff_index = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			buff[buff_index] = str[i];
			str[i] = ' ';
			buff_index++;
		}
		i++;
	}
	buff[buff_index] = '\0';
	i = 0;
	while (buff[i])
	{
		str[i] = buff[i];
		i++;
	}
	return (str);
}

char	*apply_flag_plus(char *str)
{
	int		converted_int;
	char	*converted_str;
	
	converted_int = ft_itoa(str);
	converted_str = ft_atoi(converted_int);
	return (converted_str);
}

char	*apply_flag_space(char *str)
{
	int		converted_int;
	char	*positive_result;
	int		str_len;
	
	str_len = ft_strlen(str);
	converted_int = ft_itoa(str);
	if (converted_int > 0)
	{
		*positive_result = ' ';
		*(positive_result + 1) = '\0';
		ft_strlcat(positive_result, str, str_len + 2);
		return (positive_result);
	}
	return (str);
}