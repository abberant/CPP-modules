/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:58:20 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/28 21:31:28 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	this->_filter = DEBUG;
	std::cout << "Harl is here... again" << '\n' << std::endl;
}

Harl::~Harl(void)
{
	std::cout << '\n' << "Harl left..." << std::endl;
}

void	Harl::debug(void)
{
	std::cout << GREEN << _DEBUG << RESET << std::endl;
}

void	Harl::info(void)
{
	std::cout << BLUE << _INFO << RESET << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << _WARNING << RESET << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED << _ERROR << RESET << std::endl;
}

void	Harl::setFilter(const std::string& filter)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	index;

	for (index = 0; index < 4; index++) {
		if (levels[index] == filter)
			break ;
	}
	switch (index) {
		case 0:
			_filter = DEBUG;
			break;
		case 1:
			_filter = INFO;
			break;
		case 2:
			_filter = WARNING;
			break;
		case 3:
			_filter = ERROR;
			break;
		default:
			break;
	}
}

e_Filter	Harl::getFilter(void) const
{
	return (this->_filter);
}

void	Harl::_complain(const std::string& level)
{
	void	(Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR") {
		std::cout << std::endl << "[Inaudible voices in the distance]" << std::endl;
		return ;
	}

	for (int index = _filter; index < 4; index++) {
		if (levels[index] == level) {
			(this->*ptr[index])();
			return ;
		}
	}
	std::cout << std::endl << "..." << std::endl;
}