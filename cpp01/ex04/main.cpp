/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:10:29 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/24 15:03:36 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NotSed.hpp"

int	main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	FileReplacer(av[1], av[2], av[3]);
	return (0);
}