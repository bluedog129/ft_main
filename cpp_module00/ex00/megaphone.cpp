/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 01:14:27 by choihyojong       #+#    #+#             */
/*   Updated: 2023/08/01 13:47:17 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
	{
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return 1;
	}
    for (int i = 1; argv[i]; i++)
    {
        for (int j = 0; argv[i][j]; j++)
            std::cout << static_cast<char>(std::toupper(argv[i][j]));
        if (argv[i + 1] != NULL)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}
