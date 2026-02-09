/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:08:27 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:08:27 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
   private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

   public:
	Harl();
	~Harl();
	void complain(std::string level);
};

#endif
