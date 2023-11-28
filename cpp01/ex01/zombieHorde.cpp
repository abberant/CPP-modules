/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:45:51 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/28 20:23:59 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0) {
		std::cout << "Invalid number of zombies." << std::endl;
		return nullptr;
	}
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	std::cout << "Zombie horde spawned." << std::endl;
	return (horde);
}