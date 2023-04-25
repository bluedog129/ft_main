/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_get_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:29:26 by hyojocho          #+#    #+#             */
/*   Updated: 2023/04/22 19:42:41 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	get_args_to_envp(char **args, t_arraylist *envp, t_arraylist *export)
{
	int		idx;

	idx = 1;
	while (args[++idx])
	{
		if (validate_key_args(args, idx) == ERROR)
			continue ;
		if (ft_strchr(args[idx], '=') == NULL && \
			check_same_key(args[idx], envp) == TRUE)
			continue ;
		if (ft_strchr(args[idx], '=') == NULL)
			al_add_rear(export, args[idx]);
		else
		{
			al_add_rear(export, args[idx]);
			al_add_rear(envp, args[idx]);
		}
	}
}
