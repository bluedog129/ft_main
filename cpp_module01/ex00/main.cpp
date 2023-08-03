/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:19:32 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/03 12:44:11 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* zombie = newZombie("euiclee");
	zombie->announce();
	randomChump("jinheo");
	delete zombie;
	return (0);
}