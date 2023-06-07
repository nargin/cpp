/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:59:23 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/07 19:24:42 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	return ;
}

Harl::~Harl(void) {
	return ;
}

static void toUpper(std::string &str) {
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
}

void	Harl::complain(std::string level) {
	void	(Harl::*funcPTR)(void) = NULL;
	void	(Harl::*_funcPTR[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	toUpper(level);
	for (int i = 0; i < 4; i++) {
		if (level == _levels[i]) {
			funcPTR = _funcPTR[i];
			break ;
		}
	}
	if (!funcPTR) {
		std::cout << "Invalid level" << std::endl;
		return ;
	}
	(this->*funcPTR)();
}

void	Harl::debug(void) {
	std::cout << "DEBUG: 버그가 발생해서 프로그램이 제대로 작동하지 않습니다" << std::endl;
}

void	Harl::info(void) {
	std::cout << "INFO: 보르조이 땅을 완전히" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "WARNING: 버그 수정을 위해 소프트웨어 엔지니어가 문제를 분석 중입니다" << std::endl;
}

void	Harl::error(void) {
	std::cout << "ERROR: 세그멘테이션 오류" << std::endl;
}