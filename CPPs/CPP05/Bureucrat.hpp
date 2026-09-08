/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@42student.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 18:03:24 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/08 18:03:26 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <iostream>
# include <string>

class Bureucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureucrat();
		Bureucrat(std::string name, int grade);
		Bureucrat(const Bureucrat& other);
		Bureucrat& operator=(const Bureucrat& other);
		Bureucrat& operator++();
		Bureucrat& operator--();
		~Bureucrat();
		const std::string& getName() const;
		const int getGrade() const;
};

std::ostream& operator<<(std::ostream& os, const Bureucrat& Bureucrat);

#endif
