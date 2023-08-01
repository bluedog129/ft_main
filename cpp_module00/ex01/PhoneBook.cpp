/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:57:50 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/01 21:46:40 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

bool PhoneBook::addContact(const Contact& contact) {
    if (contactCount < 8) {
        contacts[contactCount++] = contact;
        return true;
    } else {
        contacts[oldestIndex] = contact;
        oldestIndex = (oldestIndex + 1) % 8;
        return true;
    }
}

void PhoneBook::displayContacts() const {
    std::cout << std::left << std::setw(10) << "Index" << std::setw(10) << "First Name"
              << std::setw(10) << "Last Name" << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < contactCount; i++) {
        std::string firstName = contacts[i].getFirstName();
        std::string lastName = contacts[i].getLastName();
        std::string nickname = contacts[i].getNickname();
		std::string phoneNumber = contacts[i].getPhoneNumber();
		std::string darkestSecret = contacts[i].getDarkestSecret();

        // Truncate long strings to fit in 10 characters
        if (firstName.length() > 10)
            firstName = firstName.substr(0, 9) + ".";
        if (lastName.length() > 10)
            lastName = lastName.substr(0, 9) + ".";
        if (nickname.length() > 10)
            nickname = nickname.substr(0, 9) + ".";
		if (phoneNumber.length() > 10)
			phoneNumber = phoneNumber.substr(0, 9) + ".";
		if (darkestSecret.length() > 10)
			darkestSecret = darkestSecret.substr(0, 9) + ".";

        std::cout << std::setw(10) << i << std::setw(10) << firstName << std::setw(10) << lastName
                  << std::setw(10) << nickname << std::endl;
    }
}

void PhoneBook::runPhoneBookLoop() {
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickname);
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phoneNumber);
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, darkestSecret);

            Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            addContact(newContact);
        } else if (command == "SEARCH") {
            displayContacts();
            int index;
            std::cout << "Enter the index of the entry to display: ";
            std::cin >> index;
            std::cin.ignore(); // Ignore the newline character after reading the index

            if (index >= 0 && index < contactCount) {
                std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
                std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
                std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
                std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
                std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
            } else {
                std::cout << "Invalid index." << std::endl;
            }
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Try again." << std::endl;
        }
    }
}