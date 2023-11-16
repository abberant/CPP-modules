/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:58:15 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/16 00:42:19 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

enum e_Filter
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl
{
	private:

	e_Filter	_filter;

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	public:

	Harl(void);
	~Harl(void);

	void		setFilter(const std::string& filter);
	e_Filter	getFilter(void) const;
	void		_complain(const std::string& level);
};

#endif