/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choihyojong <choihyojong@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:30:17 by choihyojong       #+#    #+#             */
/*   Updated: 2023/07/09 18:50:06 by choihyojong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	ft_lstadd_back(t_map_node *lst, t_map_node *new)
{
	t_map_node	*back_pos;

	if (lst == NULL)
	{
		lst = new;
		return ;
	}
	back_pos = ft_lstlast(lst);
	back_pos -> next = new;
}

t_map_node	*ft_lstlast(t_map_node *lst)
{
	t_map_node	*dummy;

	dummy = lst;
	while (dummy != NULL && ((dummy -> next) != NULL))
		dummy = dummy -> next;
	return (dummy);
}

void	free_lst_node(t_map_node *head)
{
	t_map_node	*remove;

	if (head == NULL)
		return ;
	while (head->next != NULL)
	{
		remove = head->next;
		head->next = head->next->next;
		free(remove->line);
		free(remove);
	}
}