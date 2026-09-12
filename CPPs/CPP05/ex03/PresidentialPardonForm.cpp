/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/12 18:01:15 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/12 18:01:58 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: AForm(NAME_PRED, target, GRADE_SIGN_PRED, GRADE_EXEC_PRED){};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
