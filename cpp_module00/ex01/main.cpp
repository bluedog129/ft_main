/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choihyojong <choihyojong@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 02:17:01 by choihyojong       #+#    #+#             */
/*   Updated: 2023/08/01 02:18:33 by choihyojong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    phoneBook.addContact(Contact("John Doe", "123-456-7890"));
    phoneBook.addContact(Contact("Jane Smith", "987-654-3210"));
    phoneBook.addContact(Contact("Michael Johnson", "111-222-3333"));

    phoneBook.displayContacts();

    return 0;
}