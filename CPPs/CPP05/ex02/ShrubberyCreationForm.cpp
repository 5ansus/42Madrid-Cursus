
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	: AForm(NAME_SHRU, target, GRADE_SIGN_SHRU, GRADE_EXEC_SHRU){};

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);

	std::string		filename = getTarget() + "_shrubbery";
	std::ofstream	forest_file(filename.c_str());

	const std::string tree[] = {
		"    /\\     ",
		"   /  \\    ",
		"  /    \\   ",
		" /      \\  ",
		"/________\\ ",
		"    ||     ",
		"    ||     ",
		""
	};

	if (!forest_file.is_open())
		throw (FileError());
	for (int n_line = 0; !tree[n_line].empty(); n_line++)
	{
		for (int i = 0; i < N_TREES; i++)
			forest_file << tree[n_line];

		forest_file << std::endl;
	}
}

const char* ShrubberyCreationForm::FileError::what() const throw()
{
	return "Error opening file";
}
