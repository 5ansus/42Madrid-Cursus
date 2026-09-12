/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/12 18:01:15 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/12 18:01:58 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#define GRADE_EXEC_SHRU 137
#define GRADE_SIGN_SHRU 145
#define NAME_SHRU "ShrubberyCreationForm"
#define N_TREES 2

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(std::string const & target);
		void execute(Bureaucrat const & executor) const;

		class FileError : public std::exception{
			public:
				const char* what() const throw();
		};
};

#endif
