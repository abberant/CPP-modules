/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:28:50 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/17 23:19:32 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

void	Contact::setFirstName(std::string firstName) {
	if (firstName.empty()) {
		throw std::invalid_argument("Empty first name.");
	}
	for (std::size_t i = 0; i < firstName.size(); ++i) {
		char ch = firstName[i];
		if (!std::isalpha(ch)) {
			throw std::invalid_argument("Invalid first name.");
		}
	}
	_firstName = firstName;
}

void	Contact::setLastName(std::string lastName) {
	if (lastName.empty()) {
		throw std::invalid_argument("Empty last name.");
	}	
	for (std::size_t i = 0; i < lastName.size(); ++i) {
		char ch = lastName[i];
		if (!std::isalpha(ch)) {
			throw std::invalid_argument("Invalid last name.");
		}
	}
	_lastName = lastName;
};

void	Contact::setNickname(std::string nickname) {
	if (nickname.empty()) {
		throw std::invalid_argument("Empty nickname.");
	}
	for (std::size_t i = 0; i < nickname.size(); ++i) {
		char ch = nickname[i];
		if (!std::isalnum(ch)) {
			throw std::invalid_argument("Invalid nickname.");
		}
	}
	_nickname = nickname;
};

void	Contact::setPhoneNumber(std::string phoneNumber) {
	if (phoneNumber.empty()) {
		throw std::invalid_argument("Empty phone number.");
	}	
	for (std::size_t i = 0; i < phoneNumber.size(); ++i) {
		char digit = phoneNumber[i];
		if (!std::isdigit(digit)) {
			throw std::invalid_argument("Invalid phone number.");
		}
	_phoneNumber = phoneNumber;
	}
};

void	Contact::setDarkestSecret(std::string darkestSecret) {
	if (darkestSecret.empty()) {
		throw std::invalid_argument("Empty darkest secret.");
	}
	_darkestSecret = darkestSecret;
};

std::string	Contact::getFirstName(void) {
	return (_firstName);
};

std::string	Contact::getLastName(void) {
	return (_lastName);
};

std::string	Contact::getNickname(void) {
	return (_nickname);
};

std::string	Contact::getPhoneNumber(void) {
	return (_phoneNumber);
};

std::string	Contact::getDarkestSecret(void) {
	return (_darkestSecret);
};

void	Contact::setContact(void) {
	try {
		setInput("\tEnter first name: ", &Contact::setFirstName);
		setInput("\tEnter last name: ", &Contact::setLastName);
		setInput("\tEnter nickname: ", &Contact::setNickname);
		setInput("\tEnter phone number: ", &Contact::setPhoneNumber);
		setInput("\tEnter darkest secret: ", &Contact::setDarkestSecret);
		std::cout << "Contact added successfully!\n" << std::endl;
	} 
	catch (std::runtime_error& e) {
		clearInput(_firstName);
		clearInput(_lastName);
		clearInput(_nickname);
		clearInput(_phoneNumber);
		clearInput(_darkestSecret);
		throw std::runtime_error(e.what());
	}
	return ;
}

void 	Contact::setInput(const std::string& prompt, void (Contact::*setter)(const std::string))
{
	std::string value;
	bool isValid;

	isValid = false;
	for (int i = 0; i < 3 && !isValid; i++)
	{
		std::cout << prompt;
		std::getline(std::cin, value);
		if (std::cin.eof()) {
			std::cerr << "\ngetline() anomaly." << std::endl;
			exit(1);
		}
		try {
			(this->*setter)(value);
			isValid = true;
		}
		catch (std::exception& e) {
			std::cerr << "Invalid input: " << e.what() << std::endl;
		}
	}
	if (!isValid)
		throw std::runtime_error("Failed to set the attribute after three attempts.");
	return ;
}

void	Contact::clearInput(std::string& input) {
	input.clear();
}

void	Contact::printContact(void) {
	std::cout << std::endl;
	std::cout << "First name: " << this->getFirstName() << std::endl;
	std::cout << "Last name: " << this->getLastName() << std::endl;
	std::cout << "Nickname: " << this->getNickname() << std::endl;
	std::cout << "Phone number: " << this->getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->getDarkestSecret() << std::endl;
	std::cout << std::endl;
}
