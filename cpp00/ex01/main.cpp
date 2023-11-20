/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:29:02 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/17 19:19:39 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {
	Phonebook	phonebook;
	std::string	input;

	std::cout << "Welcome to the Phonebook!" << std::endl;
	while (!std::cin.eof()) {
		std::cout << "\nValid commands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "\nPlease enter a command: ";
		std::getline(std::cin, input);
		if (input == "EXIT") {
			std::cout << "\nBye!" << std::endl;
			break ;
		}
		else if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else
			std::cerr << "\nInvalid command. Please try again.\n" << std::endl;
	}
	return 0;
}