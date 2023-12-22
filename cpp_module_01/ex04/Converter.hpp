#ifndef CPP_MODULE_CONVERTER_HPP
#define CPP_MODULE_CONVERTER_HPP

#include "iostream"
#include "fstream"

class Converter {
public:
	void convert(char *fileName, char *s1, char *s2);

	void convert(std::string fileName, std::string s1, std::string s2);
};

#endif
