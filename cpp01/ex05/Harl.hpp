/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:55:05 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/28 21:21:05 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"

# define DEBUG "(DEBUG)\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
# define INFO "(INFO)\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING "(WARNING)\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
# define ERROR "(ERROR)\nThis is unacceptable! I want to speak to the manager now."

class Harl
{
	public:

		Harl();
		~Harl();
	
		void _complain(std::string level);

	private:

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif