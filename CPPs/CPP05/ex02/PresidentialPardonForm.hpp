
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#define GRADE_EXEC_PRED 5
#define GRADE_SIGN_PRED 25
#define NAME_PRED "PresidentialPardonForm"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(std::string const & target);
		void execute(Bureaucrat const & executor) const;
};

#endif
