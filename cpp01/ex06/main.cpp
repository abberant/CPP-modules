/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:58:18 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/16 16:08:42 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static void	_dialogue(Harl &harl, std::string level)
{
	harl.setFilter(level);
	std::string harl_levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "INVALID"};
	std::string barrista_lines[5] = {
		"Hello, sir. How can I help you?",
		"Certainly, sir! We offer additional toppings for an extra charge. I'll make sure to add more bacon to your order.",
		"I apologize for the inconvenience, sir, but all our burgers come with the exact same amount of bacon.",
		"I'm sorry, sir, but I'm afraid I can't do that.",
		"I'll call them for y..."   
	};

	switch (harl.getFilter()) {
		case INFO :
			barrista_lines[1] = "Sir, there is additional charge for extra bacon.";
			break;
		case WARNING :
			barrista_lines[1] = "Sir, there is additional charge for extra bacon.";
			barrista_lines[2] = "Is there anything else I can assist you with?";
            barrista_lines[3] = "Sir, please, calm down!";
			break;
		case ERROR :
			barrista_lines[1] = "Do you hear me, sir?";
			barrista_lines[2] = "Is there anything I can assist you with?";
			barrista_lines[3] = "Okay? Have a nice day then.";
			barrista_lines[4] = "*sighs*";
			break;
		default :
			break;
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << "[Barrista]: \n" << barrista_lines[i] << '\n' << std::endl;
		std::cout << "[Harl]: \n";
		harl._complain(harl_levels[i]);
		std::cout << std::endl;
	}
	return ;
}

static bool	check_args(char *arg)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == arg)
			return (true);
	}
	return (false);
}

int main (int argc, char **argv)
{
	Harl harl;

	if (argc > 2 || (argv[1] && !check_args(argv[1])))
	{
		std::cout << "[Probably complaining about insignificant problems]" << std::endl;
		return (1);
	}
	if (argc == 2)
		_dialogue(harl, argv[1]);
	else
		_dialogue(harl, "DEBUG");
	std::cout << "[Barrista] (to another empolyee):" << std::endl;
	std::cout << "I think I'm gonna quit this job." << std::endl;
	return (0);
}