/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:55:03 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/28 21:29:25 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl arrived." << '\n' << std::endl;
	return ;
}

Harl::~Harl()
{
	std::cout << '\n' << "Harl left." << std::endl;
	return ;
}

void	Harl::debug(void)
{

	std::cout << GREEN << DEBUG << RESET << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << BLUE << INFO << RESET << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << WARNING << RESET << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << RED << ERROR << RESET << std::endl;
	return ;
}

void	Harl::_complain(std::string level)
{
	void	(Harl::*lvls[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int		i;

	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*lvls[i])();
			return ;
		}
		i++;
	}
	std::cout << std::endl << "[Inaudible voices in the distance]" << std::endl;
	return ;
}

