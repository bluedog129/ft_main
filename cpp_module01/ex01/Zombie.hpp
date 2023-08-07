/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:57:20 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/07 15:19:54 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	void announce(void);
	void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif