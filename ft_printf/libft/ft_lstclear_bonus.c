/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:44:06 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/04 15:17:00 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*dummy;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		dummy = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = dummy;
	}
}
