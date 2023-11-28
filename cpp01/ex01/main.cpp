/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:37:28 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/28 20:21:24 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* horde = zombieHorde(0, "Hyde");
	if (!horde)
		return 1;
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	return 0;
}