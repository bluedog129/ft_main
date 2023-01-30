/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylist_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:13:02 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/30 19:42:20 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAYLIST_BONUS_H
# define FT_ARRAYLIST_BONUS_H

# define INITIAL_CAPACITY 4

typedef struct arrayList
{
	int		size;
	int		capacity;
	char	*data;
}	t_arrayList;

void	al_init(t_arrayList *list);

void	al_insert_back(t_arrayList *list, char value);

void	al_insert_front(t_arrayList *list, char value);

void	al_remove_back(t_arrayList *list);

void	al_remove_front(t_arrayList *list);

void	al_reset(t_arrayList *list);

char	al_get(t_arrayList *list, int index);

#endif