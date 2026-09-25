#ifndef CONVERTER_TPP
# define CONVERTER_TPP
# ifndef CONVERTER_HPP
#  error __FILE__ has to be included only from its .hpp
# endif

#include <sstream>
#include <iomanip>
#include <limits>

template<typename T>
bool isType(const std::string& input, T* data)
{
	std::stringstream ss(input);
	ss >> *data;
	return !ss.fail() && ss.eof();
}


template <>
inline bool isType<float>(const std::string& input, float *data)
{
	std::stringstream ss(input);

	ss >> *data;

	if (ss.fail())
		return false;

	std::string suffix;
	ss >> suffix;

	if (suffix.empty())
		return false;

	return suffix == "f" && ss.eof();
}

template <typename T, typename V>
T cast(V* input_parseado)
{
	return static_cast<T>(*input_parseado);
}

template <typename T>
std::string get_integer_string(const T& input)
{
	std::stringstream input_str;
	input_str << std::fixed << std::setprecision(Converter::DECIMAL_PRECISION) << input;
	std::string ret = input_str.str();
	size_t point_pos = ret.find('.');
	return ret.substr(0, point_pos);
}

template <typename T>
std::string get_integer_string_char(const T& input)
{
	int	valor = static_cast<int>(input);
	if (input < static_cast<T>(std::numeric_limits<char>::min()) ||
		input > static_cast<T>(std::numeric_limits<char>::max()))
		return "ErrorString";
	std::stringstream input_str;
	input_str << std::fixed << std::setprecision(Converter::DECIMAL_PRECISION) << valor;
	std::string ret = input_str.str();
	size_t point_pos = ret.find('.');
	return ret.substr(0, point_pos);
}


template<typename T>
void	print_to_all_types(T casted_value){
	std::string	casted_string;

	casted_string = get_integer_string(casted_value);

	char c = static_cast<char>(casted_value);
	if (get_integer_string_char(casted_value) == casted_string)
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			print_error("char: Non displayable");
	else{
		print_error("char: impossible");
	}

	int i = static_cast<int>(casted_value);
	if (get_integer_string(i) == casted_string)
		std::cout << "int: " << i << std::endl;
	else
		print_error("int: impossible");

	float f = static_cast<float>(casted_value);
	if (get_integer_string(f) == casted_string)
		print_decimal(f);
	else
		print_error("float: impossible");

	double d = static_cast<double>(casted_value);
	if (get_integer_string(d) == casted_string)
		print_decimal(d);
	else
		print_error("double: impossible");
}

template<typename T>
bool genericConversion(const std::string& input){
	T			casted_value;

	if (!isType<T>(input, &casted_value))
		return false;

	print_to_all_types(casted_value);

	return true;
}

template<typename T>
void print_special(T *special_number) {

	float f = cast<float, T>(special_number);
	double d = cast<double, T>(special_number);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

template<typename T>
bool special_conversion(const std::string& input){
	T			casted_value;

	if (!is_special_string(input, &casted_value))
		return false;

	print_special<T>(&casted_value);

	return true;
}


#endif
