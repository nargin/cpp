/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:06:22 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/07 18:51:04 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void findAndReplace(std::string& str, const std::string& findStr, const std::string& replaceStr) {
	size_t startPos = 0;
	while ((startPos = str.find(findStr, startPos)) != std::string::npos) {
		str = str.substr(0, startPos) + replaceStr + str.substr(startPos + findStr.length());
		startPos += replaceStr.length();
	}
}

int		main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "usage: ./replace [filename] [s1] [s2]" << std::endl;
		return (0);
	}
	if (std::string(av[1]).find('/') != std::string::npos
		|| (std::string(av[1]).empty()
		|| std::string(av[2]).empty()
		|| std::string(av[3]).empty())) {
		std::cout << "File in same directory and strings can't be empty\nI make the rules (:" << std::endl;
		return (0);
	}
	std::string		buffer;
	std::string		line;
	std::ifstream	ifs(av[1], std::ios::binary);
	if (ifs.is_open())
	{
		while (std::getline(ifs, buffer))
			line.append(buffer).append("\n");
		findAndReplace(line, av[2], av[3]);
		ifs.close();
		std::string newFileName = std::string(av[1]) + ".replace";
		std::fstream newFile(newFileName.c_str(), std::ios::out | std::ios::trunc);
		if (newFile.is_open()) {
			newFile << line;
			newFile.close();
		}
		else {
			std::cout << "Unable to open file" << std::endl;
			return (0);
		}
	}
	else {
		std::cout << "Unable to open file" << std::endl;
		return (0);
	}
	return (0);
}
