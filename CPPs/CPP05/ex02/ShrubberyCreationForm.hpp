
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#define GRADE_EXEC_SHRU 137
#define GRADE_SIGN_SHRU 145
#define NAME_SHRU "ShrubberyCreationForm"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(std::string const & target);
		void execute(Bureaucrat const & executor) const;
};

#endif
