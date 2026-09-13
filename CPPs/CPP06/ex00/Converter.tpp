#ifndef CONVERTER_TPP
# define CONVERTER_TPP
# ifndef CONVERTER_HPP
#  error __FILE__ has to be included only from its .hpp
# endif

#include <sstream>

template<typename T>
bool isType(std::string& input)
{
	T data_void;
	std::stringstream ss(input);
	ss >> data_void;
	return !ss.fail() && ss.eof();
}

template <typename T, typename V>
T cast(V input_parseado)
{
	return static_cast<T>(input_parseado);
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

#endif
