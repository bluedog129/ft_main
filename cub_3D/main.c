/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choihyojong <choihyojong@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:05:00 by hyojocho          #+#    #+#             */
/*   Updated: 2023/07/09 16:57:46 by choihyojong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

int main(int argc, char **argv)
{
	t_map			map_info;
	t_parse_info	parse_info;
	
	validate_args(argc, argv[1]);
	parse_cub_file(argv[1], &map_info, &parse_info);
}
