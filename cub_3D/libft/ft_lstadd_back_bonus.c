/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:08:33 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/04 16:30:11 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back_pos;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	back_pos = ft_lstlast(*lst);
	back_pos -> next = new;
}
