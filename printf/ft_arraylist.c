/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:31:28 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/26 14:25:27 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	al_init(t_arrayList *list)
{
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
	list->data = malloc(sizeof(int) * list->capacity);
	if (list->data == NULL)
		return ;
}

void	al_insert_back(t_arrayList *list, char value)
{
	char	*temp;

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

void	al_reset(t_arrayList *list)
{
	list->size = 0;
}

char	al_get(t_arrayList *list, int index)
{
	return (list->data[index]);
}
