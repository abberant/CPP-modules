/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:47:17 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/19 16:29:44 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "Zombie simulation started." << std::endl;

	std::cout << std::endl;

	randomChump("Zombie1");

	std::cout << std::endl;

	Zombie* z2 = newZombie("Zombie2");
	z2->announce();

	delete z2;

	std::cout << std::endl;

	std::cout << "Zombie simulation ended." << std::endl;
	return (0);
}