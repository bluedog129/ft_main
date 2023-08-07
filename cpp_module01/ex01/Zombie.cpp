/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:01:37 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/07 15:19:45 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

void Zombie::announce(void)
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}