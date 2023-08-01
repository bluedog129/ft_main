/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 01:59:23 by choihyojong       #+#    #+#             */
/*   Updated: 2023/08/01 21:41:04 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8]; // Array of contacts
    int contactCount; // Number of contacts currently in the phonebook
    int oldestIndex; // Index of the oldest contact in the array

public:
	PhoneBook();

	bool addContact(const Contact& contact);
	void displayContacts() const;
	void runPhoneBookLoop();
};

#endif