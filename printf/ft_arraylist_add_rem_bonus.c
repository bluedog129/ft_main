/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylist_add_rem_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:22:13 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/30 19:44:02 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	al_insert_back(t_arrayList *list, char value)
{
	char	*temp;

	if (list->size + 1 >= list->capacity)
	{
		list->capacity += 10;
		temp = list->data;
		list->data = malloc(sizeof(char) * list->capacity);
		if (list->data == NULL)
			return ;
		ft_memcpy(list->data, temp, sizeof(char) * list->size);
		free(temp);
		temp = NULL;
	}
	list->data[list->size++] = value;
	list->data[list->size] = '\0';
}

void	al_insert_front(t_arrayList *list, char value)
{
	char	*temp;
	int		i;

	if (list->size + 1 >= list->capacity)
	{
		list->capacity *= 2;
		temp = list->data;
		list->data = malloc(sizeof(char) * list->capacity);
		if (list->data == NULL)
			return ;
		ft_memcpy(list->data, temp, sizeof(char) * list->size);
		free(temp);
		temp = NULL;
	}
	i = list->size;
	while (i > 0)
	{
		list->data[i] = list->data[i - 1];
		i--;
	}
	list->data[0] = value;
	list->size++;
}

void	al_remove_back(t_arrayList *list)
{
	list->data[list->size] = '\0';
	list->size--;
}

void	al_remove_front(t_arrayList *list)
{
	int	i;

	i = 0;
	while (i <= list->size)
	{
		list->data[i] = list->data[i + 1];
		i++;
	}
	list->size--;
}
