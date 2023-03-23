/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:10:38 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/21 21:35:21 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	return_error_message(char *str)
{
	int	str_len;

	str_len = 0;
	while (str[str_len])
		str_len++;
	write(2, str, str_len);
}
