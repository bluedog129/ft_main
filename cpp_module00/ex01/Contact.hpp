/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:53:44 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/02 19:46:36 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
    int         index;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    std::string printLen(std::string str) const;
    std::string getInput(std::string str) const;

public:
    void    initialize(void);
    void    printEssentialContact(int index) const;
    void    printContactDetails(int index) const;
    void    setIndex(int i);
};

#endif
