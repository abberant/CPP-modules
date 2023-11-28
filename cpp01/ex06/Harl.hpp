/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:58:15 by aanouari          #+#    #+#             */
/*   Updated: 2023/11/28 21:18:43 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"

# define _DEBUG "(DEBUG)\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
# define _INFO "(INFO)\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define _WARNING "(WARNING)\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
# define _ERROR "(ERROR)\nThis is unacceptable! I want to speak to the manager now."

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