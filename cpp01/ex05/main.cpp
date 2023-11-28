/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:55:01 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/28 21:26:06 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	barrista_dialogue(std::string line)
{
	std::cout << "[Barrista]: \n" << line << std::endl << std::endl;
	return ;
}

void	harl_dialogue(Harl &harl, std::string level)
{
	std::cout << "[Harl]: ";
	harl._complain(level);
	std::cout << std::endl;
	return ;
}

static void _dialogue(Harl &harl)
{
	std::string harl_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string barrista_lines[5] = {
		"Hello, sir. How can I help you?",
		"Certainly, sir! We offer additional toppings for an extra charge. I'll make sure to add more bacon to your order.",
		"I apologize for the inconvenience, sir, but all our burgers come with the exact same amount of bacon.",
		"I'm sorry, sir, but I'm afraid I can't do that.",
		"I'll call them for y..."   
	};

	for (int i = 0; i < 5; i++)
	{
		barrista_dialogue(barrista_lines[i]);
		harl_dialogue(harl, harl_levels[i]);
	}
	return ;
}

int main(void)
{
	Harl	harl;

	_dialogue(harl);
	std::cout << "[Barrista] (to another empolyee):" << std::endl;
	std::cout << "I think I'm gonna quit this job." << std::endl;
	return (0);
}