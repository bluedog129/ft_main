/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:53:38 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/02 16:49:11 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>

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
