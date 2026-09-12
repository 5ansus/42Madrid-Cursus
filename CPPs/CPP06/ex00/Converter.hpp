#ifndef CONVERTER_HPP
#define CONVERTER_HPP
#include <iostream>
#include <string>

class Converter {
	public:

	private:
		Converter();
		Converter(const Converter& other);
		Converter& operator=(const Converter& other);
		~Converter();

	public:
		void convert(const std::string& input) const;
};
#endif
