/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:28:43 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/13 00:20:18 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Phonebook::Phonebook(void) {
	_index = 0;
	_contactCount = 0;
	return ;
}

Phonebook::~Phonebook(void) {
	return ;
}

void	Phonebook::addContact(void) {
	try {
		_contacts[_index % 8].setContact();
		if (_contactCount < 8)
			_contactCount++;
		else
			std::cout << "Phonebook is full. Oldest register have been replaced." << std::endl;
		_index++;
	}
	catch (std::runtime_error& e) {
		std::cout << "Contact not added: " << e.what() << std::endl;
	}
	return ;
}

void	Phonebook::searchContact(void) {
	std::stringstream	ss;
	std::string 		input;
	
	print_line("Index", "First Name", "Last Name", "Nickname");
	print_line("----------", "----------", "----------", "----------");
	for (int i = 0; i < _contactCount; i++) {
		ss.str("");
		ss << i;
		print_line(ss.str(), _contacts[i].getFirstName(), _contacts[i].getLastName(), _contacts[i].getNickname());
	}
	std::cout << std::endl;
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cerr << "\ngetline() anomaly." << std::endl;
		exit(0);
	}
	if (input.length() == 1 && input[0] >= '0' && input[0] <= '7' && input[0] - '0' < _contactCount)
		_contacts[input[0] - '0'].printContact();
	else
		std::cout << "\nError: Invalid index.\n" << std::endl;
	return ;
}

void	print_line(std::string index, std::string first_name, std::string last_name, std::string nickname) {
	
	std::cout << "|";
	print_field(index);
	std::cout << "|";
	print_field(first_name);
	std::cout << "|";
	print_field(last_name);
	std::cout << "|";
	print_field(nickname);
	std::cout << "|" << std::endl;
	return ;
}

void	print_field(std::string field) {
	std::string	truncatedText;
	int 		padding;
	
	if (field.length() > 10)
		truncatedText = field.substr(0, 9) + ".";
	else
		truncatedText = field;
	padding = 10 - truncatedText.length();
	for (int i = 0; i < padding; ++i) {
		std::cout << " ";
	}
	std::cout << truncatedText;
	return ;
}
