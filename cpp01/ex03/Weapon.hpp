/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:42:40 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/14 15:52:49 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:

		std::string _type;

	public:
	
		Weapon();
		Weapon(const std::string type);
		~Weapon();
		
		void setType(std::string newType);
		
		std::string const &getType();
};

#endif