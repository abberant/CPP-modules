/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:42:30 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/14 15:51:01 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
	return ;
}

Weapon::Weapon(const std::string type) : _type(type) {
	return ;
}

Weapon::~Weapon() {
	return ;
}

void Weapon::setType(std::string newType) {
	this->_type = newType;
	return ;
}

std::string const &Weapon::getType() {
	return (this->_type);
}