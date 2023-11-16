/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:49:43 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/13 20:56:43 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie 
{
	public:

		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);
		void	setName(std::string name);
		std::string	getName(void);

	private:
	
		std::string _name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif