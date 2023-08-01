/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 02:15:08 by choihyojong       #+#    #+#             */
/*   Updated: 2023/08/01 21:46:46 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

    public:
		Contact();
		Contact(const std::string firstName, const std::string lastName, 
				const std::string nickname, const std::string phoneNumber, 
				const std::string darkestSecret);
		
		void setFirstName(const std::string& firstName);
		void setLastName(const std::string& lastName);
		void setNickname(const std::string& nickname);
		void setPhoneNumber(const std::string& phoneNumber);
		void setDarkestSecret(const std::string& darkestSecret);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};

#endif