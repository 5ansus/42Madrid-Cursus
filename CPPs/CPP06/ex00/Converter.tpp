#ifndef CONVERTER_TPP
# define CONVERTER_TPP
# ifndef CONVERTER_HPP
#  error __FILE__ has to be included only from its .hpp
# endif

#include <sstream>
#include <iomanip>

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

void print_decimal(float number)
{
	std::cout << "float: " << std::fixed
		<< std::setprecision(Converter::DECIMAL_PRECISION) << number << "f" << std::endl;
}

void print_decimal(double number)
{
	std::cout << "double: " << std::fixed
		<< std::setprecision(Converter::DECIMAL_PRECISION) << number << std::endl;
}


template<typename T>
void	print_to_all_types(T casted_value){
	std::string	casted_string;

	casted_string = get_integer_string(casted_value);

	int i = static_cast<int>(casted_value);
	if (get_integer_string(i) == casted_string)
		std::cout << "int: " << i << std::endl;


	float f = static_cast<float>(casted_value);
	if (get_integer_string(f) == casted_string){
		print_decimal(f);
	}

	double d = static_cast<double>(casted_value);
	if (get_integer_string(d) == casted_string)
		print_decimal(d);
}

template<typename T>
bool genericConversion(const std::string& input){
	T			casted_value;

	if (!isType<T>(input, &casted_value))
		return false;

	print_to_all_types(casted_value);

	return true;
}

#endif
