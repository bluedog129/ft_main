/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:03:09 by choihyojong       #+#    #+#             */
/*   Updated: 2023/08/08 16:50:07 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("default"){
	std::cout << "Zombie is born" << std::endl;
}

Zombie::Zombie(std::string name) :_name(name) {
	std::cout << _name << "Zombie is born" << std::endl;
}

void Zombie::announce(void) {
    std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << _name << " is dead" << std::endl;
}