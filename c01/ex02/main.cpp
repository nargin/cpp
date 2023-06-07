/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:41:10 by codespace         #+#    #+#             */
/*   Updated: 2023/06/07 01:47:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Pointer: " << &str << std::endl;
    std::cout << "Pointer: " << stringPTR << std::endl;
    std::cout << "Reference: " << &stringREF << std::endl;
    std::cout << "String: " << str << std::endl;
    std::cout << "String: " << *stringPTR << std::endl;
    std::cout << "String: " << stringREF << std::endl;
    return 0;
}