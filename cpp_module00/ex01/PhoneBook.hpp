/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choihyojong <choihyojong@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:53:38 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/03 01:07:34 by choihyojong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>
#include <iostream>

class PhoneBook
{
private:
    Contact     	contacts[8];
    std::string		readInput(void) const;
public:
    void    addContact(void);
    void    printContacts(void) const;
    void    search(void) const;
    void    printWelcomeText(void) const;
};

#endif
