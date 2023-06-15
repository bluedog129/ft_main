/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:58:04 by hyojocho          #+#    #+#             */
/*   Updated: 2023/06/15 14:08:13 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define RED "\033[1;31m"
# define PINK "\033[1;35m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define DEFAULT "\033[0m"

# include "structures.h"

enum e_philosophers_enum
{
	SUCCESS = 1,
	ERROR = -1
};

#endif