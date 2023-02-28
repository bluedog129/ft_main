/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:23:04 by hyojocho          #+#    #+#             */
/*   Updated: 2023/02/28 20:45:30 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../dequeue/dequeue.h"
# include <limits.h>

enum e_definition
{
	ERROR = -1,
	VALIDATE_PASS = 1
};

int		validate_args(int ac, char **av);
void	print_error(char *str);

#endif