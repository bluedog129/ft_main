/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choihyojong <choihyojong@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:53:18 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/03 01:07:24 by choihyojong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    PhoneBook book;
    std::string input = "";

    book.printWelcomeText();
    while (!std::cin.eof()) {
        std::cout << "> " << std::flush;
        std::getline(std::cin, input);
        
        if (input.compare("EXIT") == 0) {
            break ;
        } else if (input.compare("ADD") == 0) {
            book.addContact();
        } else if (input.compare("SEARCH") == 0) {
            book.printContacts();
            book.search();
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
    return 0;
}
