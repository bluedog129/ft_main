/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:00:58 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/28 18:02:25 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while ((*temp_s1 != '\0' || *temp_s2 != '\0'))
	{
		if (*temp_s1 < *temp_s2)
			return (-1);
		else if (*temp_s1 > *temp_s2)
			return (1);
		temp_s1++;
		temp_s2++;
	}
	return (0);
}
