/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:51:50 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/25 23:50:28 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	return ;
}

HumanA::~HumanA() {
	return ;
}

void HumanA::attack() const {
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
	return ;
}
