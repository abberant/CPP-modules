/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:43:23 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/10 16:40:42 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	if(argc >= 2) {
		for(int i = 1; i < argc; i++) {
			for(int j = 0; argv[i][j]; j++) {
				if(std::islower(argv[i][j]))
					std::cout << (char)std::toupper(argv[i][j]);
				else
					std::cout << argv[i][j];
			}
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}