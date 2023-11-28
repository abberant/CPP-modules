/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotSed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:10:26 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/28 20:49:01 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTSED_HPP
# define NOTSED_HPP

# include <iostream>
# include <fstream>

class FileReplacer
{
	private:

	std::string		_filename;
	std::string		_searched;
	std::string		_replaced;
	std::ofstream	_ofile;

	void	_replace(const std::string& line);

	public:

	FileReplacer(std::string filename, std::string searched, std::string replaced);
	~FileReplacer(void);
};

#endif