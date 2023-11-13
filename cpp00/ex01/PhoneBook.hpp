/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:26:37 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/10 23:21:20 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {
	private:
		Contact	_contacts[8];
		int		_index;
		int		_contactCount;

	public:
		Phonebook();
		~Phonebook();

		void	addContact();
		void	searchContact();
};

void	print_line(std::string index, std::string firstName, std::string lastName, std::string nickname);
void	print_field(std::string field);

#endif