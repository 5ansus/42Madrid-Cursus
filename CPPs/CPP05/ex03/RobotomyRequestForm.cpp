/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/12 18:01:15 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/12 18:01:58 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	: AForm(NAME_ROB, target, GRADE_SIGN_ROB, GRADE_EXEC_ROB){};

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);

	bool success = std::rand() % 2;
	if (success){
		std::cout << getTarget() << " has been robotomized." << std::endl;
	}
	else {
		std::cout << "Robotomized failed for " << getTarget() << std::endl;
	}
}
