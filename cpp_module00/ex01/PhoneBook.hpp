/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choihyojong <choihyojong@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 01:59:23 by choihyojong       #+#    #+#             */
/*   Updated: 2023/08/01 02:18:30 by choihyojong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8]; // Array to store contacts
    int contactCount; // Number of contacts currently in the phonebook
    int oldestIndex = 0; // Index of the oldest contact in the array

public:
    PhoneBook() : contactCount(0) {}

    bool addContact(const Contact& contact) {
        if (contactCount < 8) {
            contacts[contactCount++] = contact;
            return true;
        } else {
            // Replace the oldest contact with the new one
            contacts[oldestIndex] = contact;
            oldestIndex = (oldestIndex + 1) % 8;
            return true;
        }
    }

    void displayContacts() const {
        std::cout << "PhoneBook Contacts:" << std::endl;
        for (int i = 0; i < contactCount; i++) {
            std::cout << "Name: " << contacts[i].getName() << ", Phone Number: " << contacts[i].getPhoneNumber() << std::endl;
        }
    }
};