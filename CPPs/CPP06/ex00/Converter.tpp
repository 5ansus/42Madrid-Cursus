#ifndef CONVERTER_TPP
# define CONVERTER_TPP
# ifndef CONVERTER_HPP
#  error __FILE__ has to be included only from its .hpp
# endif

#include <sstream>

template<typename T>
bool isType(const std::string& input, T* data)
{
	std::stringstream ss(input);
	ss >> *data;
	return !ss.fail() && ss.eof();
}

// template <>
// inline bool isType<float>(const std::string& input, float *data) {


// 	std::stringstream ss(input);
// 	ss >> *data;
// 	if (ss.fail()) return false;

// 	if (ss.eof()) return true;

// 	char suffix; --> Al leer solo un char no marca el eof
// 	ss >> suffix;

// 	return (suffix == 'f' && ss.eof());
// }

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
		return true;

	return suffix == "f" && ss.eof();
}

// cast<T, char> <<-Puntero a función
// cast<T><int>
// ...

template <typename T, typename V>
T cast(V* input_parseado)
{
	return static_cast<T>(*input_parseado);
}

template <typename T>
std::string get_integer_string(const T& input)
{
	std::stringstream input_str;
	input_str << input;
	std::string ret = input_str.str();
	size_t point_pos = ret.find('.');
	return ret.substr(0, point_pos);
}

// template<typename T, typename >


template<typename T>
bool genericConversion(const std::string& input){
	T			casted_value;
	std::string	casted_string;

	if (!isType<T>(input, &casted_value))
		return false;

	casted_string = get_integer_string(casted_value);

	int i = static_cast<int>(casted_value);
	if (get_integer_string(i) == casted_string)
		std::cout << "int: " << i << std::endl;

	double d = static_cast<double>(casted_value);
	if (get_integer_string(d) == casted_string)
		std::cout << "double: " << d << std::endl;

	float f = static_cast<float>(casted_value);
	if (get_integer_string(f) == casted_string)
		std::cout << "float: " << f << std::endl;

	return true;
}

#endif
