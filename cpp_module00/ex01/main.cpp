/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 02:17:01 by choihyojong       #+#    #+#             */
/*   Updated: 2023/08/01 17:57:10 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main() 
{
    PhoneBook phoneBook;
	std::string command;
	phoneBook.runPhoneBookLoop();
	
    return 0;
}