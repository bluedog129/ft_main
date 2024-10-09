/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:57:16 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/03 19:09:40 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* zombie = zombieHorde(10, "netpractice");
	for (int i = 0; i < 10; i++)
		zombie[i].announce();
	delete[] zombie;
	return (0);
}