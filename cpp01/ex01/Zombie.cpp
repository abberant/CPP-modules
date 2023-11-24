/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:37:55 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/21 17:03:41 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	setName(name);
	std::cout << _name << " spawned." << std::endl;
}

Zombie::Zombie()
{
	setName("Random Zombie");
	std::cout << _name << " spawned." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " died." << std::endl;
}

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}

std::string Zombie::getName()
{
	return (_name);
}