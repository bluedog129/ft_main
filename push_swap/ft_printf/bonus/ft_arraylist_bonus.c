/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylist_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:31:28 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/30 19:44:07 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	al_init(t_arrayList *list)
{
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
	list->data = malloc(sizeof(int) * list->capacity);
	if (list->data == NULL)
		return ;
}

void	al_reset(t_arrayList *list)
{
	list->size = 0;
}

char	al_get(t_arrayList *list, int index)
{
	return (list->data[index]);
}
