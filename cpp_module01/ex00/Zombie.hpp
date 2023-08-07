/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:37:58 by choihyojong       #+#    #+#             */
/*   Updated: 2023/08/07 14:56:49 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string _name;
public:
    Zombie(std::string name);
	~Zombie(void);
    void announce(void);
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif