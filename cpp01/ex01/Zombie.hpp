/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:38:04 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/13 21:46:41 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:

		std::string _name;

	public:

		Zombie(std::string name);
		Zombie();
		~Zombie();

		void announce();
		void setName(std::string name);
		std::string getName();
};

Zombie* zombieHorde(int N, std::string name);

#endif