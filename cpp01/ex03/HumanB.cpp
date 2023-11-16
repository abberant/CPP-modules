/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:10:54 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/14 16:15:06 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : _name(name) {
	return ;
}

HumanB::~HumanB() {
	return ;
}

void HumanB::attack() const {
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	return ;
}

void HumanB::setWeapon(Weapon &newWeapon) {
	this->_weapon = &newWeapon;
	return ;
}
