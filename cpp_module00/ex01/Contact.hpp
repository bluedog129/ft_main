/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choihyojong <choihyojong@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 02:15:08 by choihyojong       #+#    #+#             */
/*   Updated: 2023/08/01 02:16:36 by choihyojong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact {
    public:
        Contact() : name(""), phoneNumber("") {}
        Contact(const std::string& name, const std::string& phoneNumber) : name(name), phoneNumber(phoneNumber) {}

        std::string getName() const { return name; }
        std::string getPhoneNumber() const { return phoneNumber; }

        void setName(const std::string& newName) { name = newName; }
        void setPhoneNumber(const std::string& newPhoneNumber) { phoneNumber = newPhoneNumber; }

    private:
        std::string name;
        std::string phoneNumber;
};