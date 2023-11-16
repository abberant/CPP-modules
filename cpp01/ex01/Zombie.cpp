/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:37:55 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/13 21:47:11 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	setName(name);
	std::cout << this->_name << " spawned." << std::endl;
}

Zombie::Zombie()
{
	setName("Random Zombie");
	std::cout << this->_name << " spawned." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " died." << std::endl;
}

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

std::string Zombie::getName()
{
	return (this->_name);
}