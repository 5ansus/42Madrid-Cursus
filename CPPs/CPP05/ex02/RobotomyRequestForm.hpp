
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#define GRADE_EXEC_ROB 45
#define GRADE_SIGN_ROB 72
#define NAME_ROB "RobotomyRequestForm"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(std::string const & target);
		void execute(Bureaucrat const & executor) const;
};

#endif
