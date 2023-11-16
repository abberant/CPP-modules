/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotSed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:10:27 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/15 16:50:26 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NotSed.hpp"

FileReplacer::FileReplacer(std::string filename, std::string searched, std::string replaced) :
    _filename(filename), _searched(searched), _replaced(replaced)
{
	std::ifstream	ifile(filename);
	std::string		line;

	if (!ifile)
	{
		std::cout << "Error opening file: " << filename << "." << std::endl;
		return ;
	}
	_ofile.open(filename + ".replace");
	if (!_ofile)
	{
		std::cout << "Error creating output file " << filename << ".replace." << std::endl;
		return ;
	}
	while (std::getline(ifile, line)) {
		replace(line);
		if (!ifile.eof())
			_ofile << std::endl;
	}
	ifile.close();
	_ofile.close();
}

FileReplacer::~FileReplacer(void)
{
	return ;
}

void	FileReplacer::replace(const std::string& line)
{
	std::string::size_type	pos = 0;
	std::string::size_type	prev = 0;

	while ((pos = line.find(_searched, pos)) != std::string::npos)
	{
		_ofile << line.substr(prev, pos - prev) << _replaced;
		pos += _searched.length();
		prev = pos;
	}
	_ofile << line.substr(prev);
}