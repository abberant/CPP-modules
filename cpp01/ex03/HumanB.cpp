/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:10:54 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/24 14:59:53 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : _name(name) {
	return ;
}

HumanB::~HumanB() {
	return ;
}

void	HumanB::attack() const {
	if (_weapon == NULL)
		std::cout << _name << " has no weapon." << std::endl;
	else
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon) {
	_weapon = &newWeapon;
}
