/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choihyojong <choihyojong@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:53:31 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/03 01:25:58 by choihyojong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getInput(std::string str) const {
    std::string input = "";
	
	while (true)
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            break;
        else {
			if (std::cin.eof())
				exit(1);
            std::cin.clear();
            std::cout << "Invalid input; please try again." << std::endl;
        }
	}
    return (input);
}

void    Contact::initialize(void) {
    this->firstName = this->getInput("Please enter you first name: ");
    this->lastName = this->getInput("Please enter your last name: ");
    this->nickname = this->getInput("Please enter your nickname: ");
    this->phoneNumber = this->getInput("Please enter your phone number: ");
    this->darkestSecret = this->getInput("Please enter your darkest secret: ");
    std::cout << std::endl;
}

std::string Contact::printLen(std::string str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::setIndex(int index) {
    this->index = index;
}

void    Contact::printEssentialContact(int index) const {
    if (this->firstName.empty() || this->lastName.empty() || this->nickname.empty())
        return ;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << this->printLen(this->firstName) << std::flush;
    std::cout << "|" << std::setw(10) << this->printLen(this->lastName) << std::flush;
    std::cout << "|" << std::setw(10) << this->printLen(this->nickname) << std::flush;
    std::cout << "|" << std::endl;
}

void    Contact::printContactDetails(int index) const {
    if (this->firstName.empty() || this->lastName.empty() || this->nickname.empty())
        return ;
    std::cout << std::endl;
    std::cout << "------- CONTACT # " << index << " index # -------" << std::endl;
    std::cout << "First Name:\t" << this->firstName << std::endl;
    std::cout << "Last Name:\t" << this->lastName << std::endl;
    std::cout << "Nickname:\t" << this->nickname << std::endl;
	std::cout << "Phone Number:\t" << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret:\t" << this->darkestSecret << std::endl;
    std::cout << std::endl;
}
