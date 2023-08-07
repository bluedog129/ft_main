/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:53:24 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/05 17:59:07 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void    PhoneBook::printWelcomeText(void) const {
    std::cout << std::endl;
    std::cout << "        Welcome to My Awesome  📞📖        " << std::endl;
    std::cout << std::endl;
    std::cout << "------------------manual-------------------" << std::endl;
    std::cout << "ADD\t: Function to add a contact." << std::endl;
    std::cout << "SEARCH\t: Function to search for a contact." << std::endl;
    std::cout << "EXIT\t: Function to quite the PhoneBook." << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::addContact(void) {
	static int  index;

    this->contacts[index % 8].initialize();
    this->contacts[index % 8].setIndex(index % 8);
    index++;
}

void    PhoneBook::printContacts(void) const {
    std::cout << "------------- PHONBOOK CONTACTS -------------" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << std::flush;
	std::cout << "|" << std::setw(10) << "First Name" << std::flush;
	std::cout << "|" << std::setw(10) << "Last Name" << std::flush;
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
    for (size_t i = 0; i < 8; i++) {
        this->contacts[i].printEssentialContact(i);
    }
    std::cout << std::endl;
}

std::string     PhoneBook::readInput() const {
    std::string input = "";
	
    while (true)
    {
        std::cout << "Please enter the contact index: " << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && input.length() == 1 && std::isdigit(input[0])) {
            break;
        } else {
			if (std::cin.eof())
				exit(1);
            std::cin.clear();
            std::cout << "Invalid index; please re-enter." << std::endl;
        }
    }
    return (input);
}

void    PhoneBook::search(void) const {
	int search_index;

    std::string index = this->readInput();
	search_index = std::strtod(index.c_str(), NULL);
    this->contacts[search_index].printContactDetails(search_index);
}
